#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* adj[MAX];
int n;
int vizitat[MAX];
int coada[MAX], st, dr;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void bfs(int startNode, FILE *out) {
    for (int i = 0; i < n; i++) vizitat[i] = 0;
    st = 0; dr = 0;

    vizitat[startNode] = 1;
    coada[dr++] = startNode;

    fprintf(out, "BFS Dinamic: ");

    while (st != dr) {
        int u = coada[st++];
        fprintf(out, "%d ", u);
        printf("%d ", u);

        Node* temp = adj[u];
        while (temp) {
            int v = temp->dest;
            if (!vizitat[v]) {
                vizitat[v] = 1;
                coada[dr++] = v;
            }
            temp = temp->next;
        }
    }
    fprintf(out, "\n");
    printf("\n");
}

int main() {
    FILE *in = fopen("graf.txt", "r");
    FILE *out = fopen("bfs_out_dinamic.txt", "w");
    if (!in) return 1;

    fscanf(in, "%d", &n);

    for (int i = 0; i < n; i++) adj[i] = NULL;

    int u, v;
    while (fscanf(in, "%d %d", &u, &v) != EOF) {
        addEdge(u, v);
    }

    int start;
    printf("Start nod: ");
    scanf("%d", &start);

    bfs(start, out);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* adj[MAX];
int pi[MAX];
int vizitat[MAX];
int n;

int stack[MAX];
int top = -1;

void push(int v) { stack[++top] = v; }
int pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void pushNeighborsReverse(int u) {
    int temp[MAX];
    int count = 0;

    Node* p = adj[u];
    while (p != NULL) {
        temp[count++] = p->dest;
        p = p->next;
    }

    for (int i = count - 1; i >= 0; i--) {
        int v = temp[i];
        if (!vizitat[v]) {
            push(v);
            if (pi[v] == -1) pi[v] = u;
        }
    }
}

void dfs_iterative(int startNode) {
    for(int i=0; i<n; i++) {
        vizitat[i] = 0;
        pi[i] = -1;
    }
    top = -1;

    push(startNode);

    printf("DFS Iterativ: ");

    while (!isEmpty()) {
        int u = pop();

        if (!vizitat[u]) {
            vizitat[u] = 1;
            printf("%d ", u);

            pushNeighborsReverse(u);
        }
    }
    printf("\n");
}

void printParents() {
    printf("\nVectorul de parinti (Arborele DFS):\n");
    for(int i=0; i<n; i++) {
        if(vizitat[i])
            printf("Nod %d -> Parinte %d\n", i, pi[i]);
    }
}

int main() {
    FILE *in = fopen("graf.txt", "r");
    if (!in) { printf("Fisierul graf.txt nu exista!"); return 1; }

    fscanf(in, "%d", &n);
    for(int i=0; i<n; i++) adj[i] = NULL;

    int u, v;
    while (fscanf(in, "%d %d", &u, &v) != EOF) {
        addEdge(u, v);
    }
    fclose(in);

    int start;
    printf("Nod de start: ");
    scanf("%d", &start);

    dfs_iterative(start);
    printParents();

    return 0;
}

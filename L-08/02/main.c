#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define ALB 0
#define GRI 1
#define NEGRU 2

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* adj[MAX];
int color[MAX];
int pi[MAX];
int d[MAX];
int f[MAX];
int timp_global;
int n;

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs_visit(int u) {
    color[u] = GRI;
    timp_global++;
    d[u] = timp_global;

    printf("%d ", u);

    Node* p = adj[u];
    while (p != NULL) {
        int v = p->dest;
        if (color[v] == ALB) {
            pi[v] = u;
            dfs_visit(v);
        }
        p = p->next;
    }

    color[u] = NEGRU;
    timp_global++;
    f[u] = timp_global;
}

void dfs_main(int startNode) {
    for (int i = 0; i < n; i++) {
        color[i] = ALB;
        pi[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }
    timp_global = 0;

    printf("DFS Recursiv: ");

    if (color[startNode] == ALB) {
        dfs_visit(startNode);
    }
    printf("\n");
}

void printDetails() {
    printf("\nDetalii Noduri:\n");
    printf("Nod\tCuloare\tParinte\td (Start)\tf (Final)\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\n", i, color[i], pi[i], d[i], f[i]);
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

    dfs_main(start);
    printDetails();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;
int mat[MAX][MAX];
int vizitat[MAX];
int coada[MAX], st, dr;

void push(int nod) {
    coada[dr++] = nod;
}

int pop() {
    return coada[st++];
}

int isEmpty() {
    return st == dr;
}

void bfs(int startNode, FILE *out) {
    for (int i = 0; i < n; i++) vizitat[i] = 0;
    st = 0; dr = 0;

    vizitat[startNode] = 1;
    push(startNode);
    fprintf(out, "BFS incepe de la %d: ", startNode);
    printf("BFS incepe de la %d: ", startNode);

    while (!isEmpty()) {
        int u = pop();
        fprintf(out, "%d ", u);
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (mat[u][v] == 1 && vizitat[v] == 0) {
                vizitat[v] = 1;
                push(v);
            }
        }
    }
    fprintf(out, "\n");
    printf("\n");
}

int main() {
    FILE *in = fopen("graf.txt", "r");
    FILE *out = fopen("bfs_out.txt", "w");
    if (!in || !out) { printf("Eroare fisiere.\n"); return 1; }

    int u, v;
    fscanf(in, "%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mat[i][j] = 0;

    while (fscanf(in, "%d %d", &u, &v) != EOF) {
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int start;
    printf("Introduceti nodul de start (0 - %d): ", n-1);
    scanf("%d", &start);

    bfs(start, out);

    fclose(in);
    fclose(out);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODURI 100
#define MAX_MUCHII 500

int n;
int index_start[MAX_NODURI];
int lista_vecini[MAX_MUCHII];
int vizitat[MAX_NODURI];
int coada[MAX_NODURI], st, dr;

void bfs(int startNode, FILE *out) {
    for(int i=0; i<n; i++) vizitat[i] = 0;
    st = 0; dr = 0;

    vizitat[startNode] = 1;
    coada[dr++] = startNode;

    fprintf(out, "BFS Static: ");

    while(st != dr) {
        int u = coada[st++];
        fprintf(out, "%d ", u);
        printf("%d ", u);

        int k = index_start[u];

        while (lista_vecini[k] != -1) {
            int v = lista_vecini[k];
            if (!vizitat[v]) {
                vizitat[v] = 1;
                coada[dr++] = v;
            }
            k++;
        }
    }
    fprintf(out, "\n");
    printf("\n");
}

int main() {
    FILE *in = fopen("graf.txt", "r");
    FILE *out = fopen("bfs_out_static.txt", "w");

    int tempAdj[MAX_NODURI][MAX_NODURI] = {0};
    int u, v;

    fscanf(in, "%d", &n);
    while (fscanf(in, "%d %d", &u, &v) != EOF) {
        tempAdj[u][v] = 1;
        tempAdj[v][u] = 1;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        index_start[i] = k;
        for (int j = 0; j < n; j++) {
            if (tempAdj[i][j] == 1) {
                lista_vecini[k++] = j;
            }
        }
        lista_vecini[k++] = -1;
    }

    int start;
    printf("Start nod: ");
    scanf("%d", &start);

    bfs(start, out);

    return 0;
}

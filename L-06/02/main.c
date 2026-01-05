typedef struct {
    int key;
    int status;
} Cell;

Cell hTableOpen[M];

void initOpenTable() {
    for (int i = 0; i < M; i++) {
        hTableOpen[i].status = 0;
    }
}

int h_linear(int key, int i) {
    return (key % M + i) % M;
}

void insertLinear(int key) {
    int i = 0;
    while (i < M) {
        int index = h_linear(key, i);
        if (hTableOpen[index].status == 0) {
            hTableOpen[index].key = key;
            hTableOpen[index].status = 1;
            printf("Inserat %d la index %d (i=%d)\n", key, index, i);
            return;
        }
        i++;
    }
    printf("Tabela este plina! Nu se poate insera %d\n", key);
}

int main_ex2() {
    initOpenTable();
    int keys[] = {19, 36, 5, 21, 4, 26, 14};
    int n = 7;

    printf("Verificare Liniara");
    for(int i=0; i<n; i++) insertLinear(keys[i]);

    return 0;
}

int h_double(int key, int i) {
    int h1 = key % M;
    int h2 = 5 - (key % 5);
    return (h1 + i * h2) % M;
}

void insertDouble(int key) {
    int i = 0;
    while (i < M) {
        int index = h_double(key, i);
        if (hTableOpen[index].status == 0) {
            hTableOpen[index].key = key;
            hTableOpen[index].status = 1;
            printf("Inserat %d la index %d (i=%d)\n", key, index, i);
            return;
        }
        i++;
    }
    printf("Nu s-a putut insera %d (verificare dubla)\n", key);
}

int main_ex4() {
    initOpenTable();
    int keys[] = {19, 36, 5, 21, 4, 26, 14};

    printf("Verificare Dubla");
    for(int i=0; i<7; i++) insertDouble(keys[i]);

    return 0;
}

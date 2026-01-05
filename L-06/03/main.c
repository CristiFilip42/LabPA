int h_quad(int key, int i) {
    int h_prime = key % M;
    int c1 = 1;
    int c2 = 1;
    return (h_prime + c1 * i + c2 * i * i) % M;
}

void insertQuad(int key) {
    int i = 0;
    while (i < M) {
        int index = h_quad(key, i);
        if (hTableOpen[index].status == 0) {
            hTableOpen[index].key = key;
            hTableOpen[index].status = 1;
            printf("Inserat %d la index %d (i=%d)\n", key, index, i);
            return;
        }
        i++;
    }
    printf("Nu s-a putut insera %d (verificare polinomiala)\n", key);
}

int main_ex3() {
    initOpenTable();
    int keys[] = {19, 36, 5, 21, 4, 26, 14};

    printf("Verificare Polinomiala");
    for(int i=0; i<7; i++) insertQuad(keys[i]);

    return 0;
}

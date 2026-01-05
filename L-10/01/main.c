#include <stdio.h>

int bancnote[] = {500, 200, 100, 50, 10, 5, 1};
int n = 7;

void descompunere(int suma) {
    printf("Suma %d se descompune in:\n", suma);

    int numarTotal = 0;

    for (int i = 0; i < n; i++) {
        int nr = suma / bancnote[i];

        if (nr > 0) {
            printf("%d x %d RON\n", nr, bancnote[i]);
            numarTotal += nr;
            suma = suma % bancnote[i];
        }
    }

    printf("Total bancnote: %d\n", numarTotal);
}

int main() {
    int x;
    printf("Descompunere Bani");
    printf("Introduceti suma: ");
    scanf("%d", &x);

    descompunere(x);

    return 0;
}

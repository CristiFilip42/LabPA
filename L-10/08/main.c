#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float greutate;
    float valoare;
    float raport;
} Obiect;

int compareRatio(const void *a, const void *b) {
    Obiect *o1 = (Obiect *)a;
    Obiect *o2 = (Obiect *)b;
    if (o2->raport > o1->raport) return 1;
    if (o2->raport < o1->raport) return -1;
    return 0;
}

void rucsacFractionar(Obiect arr[], int n, float capacitate) {
    for (int i = 0; i < n; i++) {
        arr[i].raport = arr[i].valoare / arr[i].greutate;
    }

    qsort(arr, n, sizeof(Obiect), compareRatio);

    float valoareTotala = 0.0;
    float capacitateRamasa = capacitate;

    printf("Obiecte in rucsac (Capacitate %.2f):\n", capacitate);

    for (int i = 0; i < n; i++) {
        if (capacitateRamasa <= 0) break;

        if (arr[i].greutate <= capacitateRamasa) {
            capacitateRamasa -= arr[i].greutate;
            valoareTotala += arr[i].valoare;
            printf("- Obiect %d (100%%): Greutate %.2f, Valoare %.2f\n",
                   arr[i].id, arr[i].greutate, arr[i].valoare);
        } else {
            float fractiune = capacitateRamasa / arr[i].greutate;
            valoareTotala += arr[i].valoare * fractiune;
            printf("- Obiect %d (%.2f%%): Greutate %.2f, Valoare %.2f (Fractiune)\n",
                   arr[i].id, fractiune * 100, capacitateRamasa, arr[i].valoare * fractiune);
            capacitateRamasa = 0;
        }
    }

    printf("Valoare totala in rucsac: %.2f\n", valoareTotala);
}

int main() {
    printf("Rucsac Fractionar");

    float capacitateRucsac = 50.0;
    Obiect obiecte[] = {
        {1, 10, 60},
        {2, 20, 100},
        {3, 30, 120}
    };
    int n = sizeof(obiecte) / sizeof(obiecte[0]);

    rucsacFractionar(obiecte, n, capacitateRucsac);

    return 0;
}

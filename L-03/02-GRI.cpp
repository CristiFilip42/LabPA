#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

typedef struct {
    int vec[CAPACITY];
    int cap;
    int coada;
    int marime;
} Coada;

void init(Coada* cda){
    cda->cap = 0;
    cda->coada = 0;
    cda->marime = 0;
}

void enqueue(Coada* cda, int cheie){
    if (cda->marime == CAPACITY) {
        printf("Eroare: Coada e plina!\n");
        return;
    }

    cda->vec[cda->coada] = cheie;
    cda->coada = (cda->coada + 1) % CAPACITY;
    cda->marime++;
}

int dequeue(Coada* cda){
    if (cda->marime == 0) {
        printf("Eroare: Coada e goala!\n");
        return -1;
    }

    int valoare = cda->vec[cda->cap];
    cda->cap = (cda->cap + 1) % CAPACITY;
    cda->marime--;

    return valoare;
}

void afisare(Coada *cda){
    if (cda->marime == 0) {
        printf("Coada goala.\n");
        return;
    }

    int count = 0;
    int i = cda->cap;

    while (count < cda->marime) {
        printf("%d ", cda->vec[i]);
        i = (i + 1) % CAPACITY;
        count++;
    }
    printf("\n");
}

int main(){
    Coada cda;
    init(&cda);

    enqueue(&cda, 10);
    enqueue(&cda, 20);
    enqueue(&cda, 30);

    afisare(&cda);

    dequeue(&cda);

    afisare(&cda);

    return 0;
}
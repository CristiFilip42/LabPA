#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int val;
    struct nod *urm;
    struct nod *ant;
} Nod;

typedef struct {
    Nod *cap;
    Nod *coada;
} Lista;

void init(Lista *lista) {
    lista->cap = NULL;
    lista->coada = NULL;
}

Nod* search(Lista *lista, int cheie) {
    Nod *curent = lista->cap;
    while(curent != NULL) {
        if(curent->val == cheie) {
            return curent;
        }
        curent = curent->urm;
    }
    return NULL;
}

void insert_first(Lista *lista, int valoare) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    nou->val = valoare;
    nou->ant = NULL;
    nou->urm = lista->cap;

    if(lista->cap == NULL) {
        lista->coada = nou;
    } else {
        lista->cap->ant = nou;
    }

    lista->cap = nou;
}

void insert_last(Lista *lista, int valoare) {
    Nod *nou = (Nod*)malloc(sizeof(Nod));
    nou->val = valoare;
    nou->urm = NULL;
    nou->ant = lista->coada;

    if(lista->cap == NULL) {
        lista->cap = nou;
    } else {
        lista->coada->urm = nou;
    }

    lista->coada = nou;
}

void insert_after_key(Lista *lista, int afterKey, int valoare) {
    Nod *tinta = search(lista, afterKey);

    if(tinta == NULL) {
        return;
    }

    if(tinta == lista->coada) {
        insert_last(lista, valoare);
        return;
    }

    Nod *nou = (Nod*)malloc(sizeof(Nod));
    nou->val = valoare;

    nou->urm = tinta->urm;
    nou->ant = tinta;

    tinta->urm->ant = nou;
    tinta->urm = nou;
}

void delete_first(Lista *lista) {
    if(lista->cap == NULL) return;

    Nod *de_sters = lista->cap;

    lista->cap = lista->cap->urm;

    if(lista->cap == NULL) {
        lista->coada = NULL;
    } else {
        lista->cap->ant = NULL;
    }

    free(de_sters);
}

void delete_last(Lista *lista) {
    if(lista->cap == NULL) return;

    Nod *de_sters = lista->coada;

    lista->coada = lista->coada->ant;

    if(lista->coada == NULL) {
        lista->cap = NULL;
    } else {
        lista->coada->urm = NULL;
    }

    free(de_sters);
}

void delete_key(Lista *lista, int cheie) {
    Nod *tinta = search(lista, cheie);

    if(tinta == NULL) {
        return;
    }

    if(tinta == lista->cap) {
        delete_first(lista);
        return;
    }
    if(tinta == lista->coada) {
        delete_last(lista);
        return;
    }

    tinta->ant->urm = tinta->urm;
    tinta->urm->ant = tinta->ant;

    free(tinta);
}

void print_forward(Lista *lista) {
    Nod *curent = lista->cap;
    while(curent != NULL) {
        printf("%d ", curent->val);
        curent = curent->urm;
    }
    printf("\n");
}

void print_backward(Lista *lista) {
    Nod *curent = lista->coada;
    while(curent != NULL) {
        printf("%d ", curent->val);
        curent = curent->ant;
    }
    printf("\n");
}

int main() {
    Lista lst;
    init(&lst);

    insert_last(&lst, 10);
    insert_last(&lst, 20);
    insert_first(&lst, 5);

    print_forward(&lst);

    insert_after_key(&lst, 10, 15);

    print_forward(&lst);
    print_backward(&lst);

    delete_key(&lst, 15);
    print_forward(&lst);

    return 0;
}
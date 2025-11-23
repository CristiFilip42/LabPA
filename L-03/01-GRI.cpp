#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int val;
  struct node *urm;
} Stiva;

void init(Stiva** stv){
  *stv = NULL;
}

void push(Stiva** stv, int cheie){
  Stiva* nod_nou = (Stiva*)malloc(sizeof(Stiva));

  nod_nou->val = cheie;

  nod_nou->urm = *stv;

  *stv = nod_nou;

};

Stiva* pop(Stiva** stv){
	Stiva* NodDeSters = *stv;
        *stv = (*stv)->urm;
    NodDeSters->urm = NULL;
}

void afisare(Stiva *stv){
  Stiva* current = stv;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->urm;
    }
    printf("\n");
}

int main(){
  Stiva* stva;
  init(&stva);
  push(&stva, 10);
  push(&stva, 20);
  push(&stva, 30);
  afisare(stva);
  pop(&stva);
  afisare(stva);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int lin;
  int col;
  int val;
  struct node*next;
}NodeT;

NodeT* creeare_nod(int r, int c, int v){
  NodeT *p = (NodeT*)malloc(sizeof(NodeT));
  if(p==NULL)
    exit(1);
  p->lin = r;
  p->col = c;
  p->val = v;
  p->next = NULL;
  return p;
}

void insereaza_element(NodeT **primul, int r, int c, int v){
  if(v==0)
    return;

  NodeT *nod_nou = creeare_nod(r,c,v);

  if (*primul == NULL || ((*primul)->lin > r) || ((*primul)->lin == r && (*primul)->col > c)) {
    nod_nou->next = *primul;
    *primul = nod_nou;
    return;
  }

  NodeT *curent = *primul;
  NodeT *inainte = NULL;

  while (curent != NULL && (curent->lin < r || (curent->lin == r && curent->col < c))) {
    inainte = curent;
    curent = curent->next;
  }

  if (curent != NULL && curent->lin == r && curent->col == c) {
    curent->val += v;
    free(nod_nou);

  }
  else {
    inainte->next = nod_nou;
    nod_nou->next = curent;
  }
}

NodeT *adunare(NodeT *m,NodeT *m1){
  NodeT *rezultat = NULL;

  while (m != NULL && m1 != NULL) {
    if (m->lin < m1->lin || (m->lin == m1->lin && m->col < m1->col)) {
      insereaza_element(&rezultat, m->lin, m->col, m->val);
      m = m->next;
    }

    else if (m1->lin < m->lin || (m1->lin == m->lin && m->col < m1->col)) {
      insereaza_element(&rezultat, m1->lin, m1->col, m1->val);
      m1 = m1->next;
    }

    else {
      insereaza_element(&rezultat, m->lin, m->col, m->val + m1->val);
      m = m->next;
      m1 = m1->next;
    }
  }

  while (m != NULL) {
    insereaza_element(&rezultat, m->lin, m->col, m->val);
    m = m->next;
  }
  while (m1 != NULL) {
    insereaza_element(&rezultat, m1->lin, m1->col, m1->val);
    m1 = m1->next;
  }

  return rezultat;
}

NodeT* inmultire(NodeT *m, NodeT *m1) {
  NodeT *rezultat = NULL;
  NodeT *p1 = m;

  while (p1 != NULL) {
    NodeT *p2 = m1;
    while (p2 != NULL) {
      if (p1->col == p2->lin) {
        insereaza_element(&rezultat, p1->lin, p2->col, p1->val * p2->val);
      }
      p2 = p2->next;
    }
    p1 = p1->next;
  }
  return rezultat;
}

void afisare(NodeT *prim) {
  if (prim == NULL) {
    printf("Matrice vida (sau zero)\n");
    return;
  }
  while (prim != NULL) {
    if (prim->val != 0)
      printf("(%d, %d, %d) ", prim->lin, prim->col, prim->val);
    prim = prim->next;
  }
  printf("\n");
}

int main() {
  NodeT *m = NULL;
  NodeT *m1 = NULL;

  insereaza_element(&m, 0, 0, 10);
  insereaza_element(&m, 0, 1, 20);
  insereaza_element(&m, 1, 1, 5);

  insereaza_element(&m1, 0, 0, 2);
  insereaza_element(&m1, 1, 0, 4);
  insereaza_element(&m1, 1, 1, 3);

  printf("M1: "); afisare(m);
  printf("M2: "); afisare(m1);

  printf("\nSuma (M1 + M2): ");
  NodeT *suma = adunare(m, m1);
  afisare(suma);

  printf("Produs (M1 * M2): ");
  NodeT *produs = inmultire(m, m1);
  afisare(produs);

  return 0;
}




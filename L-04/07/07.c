#include <stdio.h>
#include <stdlib.h>
typedef struct node_type {
    int id;
    struct node_type *left, *right;
} NodeT;

void preorder(NodeT *p) {
    if (p != NULL) {
        printf("%d ", p->id);
        preorder(p->left);
        preorder(p->right);
    }
}
NodeT *creBalBinTree(int nbOfNodes) {
    NodeT *p;
    int nLeft, nRight;

    if (nbOfNodes <= 0) {
        return NULL;
    } else {
        nLeft = nbOfNodes / 2;
        nRight = nbOfNodes - nLeft - 1;

        p = (NodeT *) malloc(sizeof(NodeT));

        printf("Introduceti valoarea pentru un nod: ");
        scanf("%d", &p->id);

        p->left = creBalBinTree(nLeft);
        p->right = creBalBinTree(nRight);
    }
    return p;
}
int main() {
    NodeT *root;
    int n;
    printf("Ex 7: Arbore echilibrat.n = ");
    scanf("%d", &n);

    printf(" Introduceti cele %d valori ", n);
    root = creBalBinTree(n);

    printf("Afisare Arbore");
    preorder(root);

    return 0;
}

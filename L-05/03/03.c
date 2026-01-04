void inOrder(NodeT *p) {
    if (p != NULL) {
        inOrder(p->left);
        printf("%d ", p->key);
        inOrder(p->right);
    }
}

void preOrder(NodeT *p) {
    if (p != NULL) {
        printf("%d ", p->key);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(NodeT *p) {
    if (p != NULL) {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ", p->key);
    }
}

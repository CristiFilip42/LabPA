//EX 2
void inorder(NodeT *p) {
    if (p != NULL) {
        inorder(p->left);
        printf("%d ", p->id);
        inorder(p->right);
    }
}
void postorder(NodeT *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->id);
    }
}

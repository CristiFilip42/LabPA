//EX 5

int maxim(int a, int b) {
    return (a > b) ? a : b;
}
int height(NodeT *node) {
    if (node == NULL) {
        return -1;
    }

    return 1 + maxim(height(node->left), height(node->right));
}

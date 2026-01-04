// EX 4
int internal_nodes(NodeT *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 0;
    }
    return 1 + internal_nodes(node->left) + internal_nodes(node->right);
}

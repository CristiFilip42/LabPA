//EX 3
int leaf_node(NodeT *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    return leaf_node(node->left) + leaf_node(node->right); // [cite: 140]
}

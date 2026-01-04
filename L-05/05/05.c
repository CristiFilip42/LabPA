NodeT* findMax(NodeT* node) {
    if (node == NULL) return NULL;

    NodeT* current = node;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

NodeT* findMin(NodeT* node) {
    if (node == NULL) return NULL;

    NodeT* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

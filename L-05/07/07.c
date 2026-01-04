NodeT* predecesor(NodeT* root, NodeT* node) {
    if (node->left != NULL) {
        return findMax(node->left);
    }

    NodeT* pred = NULL;
    NodeT* current = root;

    while (current != NULL) {
        if (node->key > current->key) {
            pred = current;
            current = current->right;
        } else if (node->key < current->key) {
            current = current->left;
        } else {
            break;
        }
    }
    return pred;
}

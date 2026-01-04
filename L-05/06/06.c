NodeT* succesor(NodeT* root, NodeT* node) {
    if (node->right != NULL) {
        return findMin(node->right);
    }

    NodeT* succ = NULL;
    NodeT* current = root;

    while (current != NULL) {
        if (node->key < current->key) {
            succ = current;
            current = current->left;
        } else if (node->key > current->key) {
            current = current->right;
        } else {
            break;
        }
    }
    return succ;
}

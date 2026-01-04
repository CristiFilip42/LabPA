NodeT* insertNode(NodeT* root, int key) {
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        return newNode;
    }

    NodeT* current = root;
    NodeT* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            free(newNode);
            return root;
        }
    }

    if (key < parent->key) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

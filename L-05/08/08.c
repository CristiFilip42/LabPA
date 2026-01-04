NodeT* deleteNode(NodeT* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            NodeT* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodeT* temp = root->left;
            free(root);
            return temp;
        }
        NodeT* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

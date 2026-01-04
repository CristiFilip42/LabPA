NodeT* searchKey(NodeT* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return searchKey(root->left, key);
    } else {
        return searchKey(root->right, key);
    }
}

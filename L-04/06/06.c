//EX 6
NodeT *search(NodeT *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->id == key) {
        return root;
    }

    NodeT *gasitInStanga = search(root->left, key);

    if (gasitInStanga != NULL) {
        return gasitInStanga;
    }
    return search(root->right, key);
}

//EX1
fscanf(f, "%d", &c);

if (c == 0) {
    return NULL;
} else {
    p->id = c;
    p->left = createBinTreeFromFile(f);
    p->right = createBinTreeFromFile(f);

    return p;
}

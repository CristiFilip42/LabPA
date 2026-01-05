#include <stdio.h>
#include <stdlib.h>

#define M 7

typedef struct node {
    int key;
    struct node *next;
} NodeT;

NodeT* hTable[M];

void initHashTable() {
    for (int i = 0; i < M; i++) {
        hTable[i] = NULL;
    }
}

int h(int key) {
    return key % M;
}

void insertElement(NodeT* hTable[], int key) {
    int index = h(key);

    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->key = key;

    newNode->next = hTable[index];
    hTable[index] = newNode;

    printf("Inserat %d la indexul %d\n", key, index);
}

NodeT* findElement(NodeT* hTable[], int key) {
    int index = h(key);
    NodeT* p = hTable[index];

    while (p != NULL) {
        if (p->key == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void deleteElement(NodeT* hTable[], int key) {
    int index = h(key);
    NodeT *p = hTable[index];
    NodeT *prev = NULL;

    while (p != NULL) {
        if (p->key == key) {
            if (prev == NULL) {
                hTable[index] = p->next;
            } else {
                prev->next = p->next;
            }
            free(p);
            printf("Sters %d de la indexul %d\n", key, index);
            return;
        }
        prev = p;
        p = p->next;
    }
    printf("Elementul %d nu a fost gasit pentru stergere.\n", key);
}

void printTable() {
    for (int i = 0; i < M; i++) {
        printf("Slot %d: ", i);
        NodeT* p = hTable[i];
        while (p != NULL) {
            printf("%d -> ", p->key);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main_ex1() {
    initHashTable();
    int keys[] = {36, 14, 26, 21, 5, 19, 4};
    int n = 7;

    printf("--- Ex 1: Chaining ---\n");
    for(int i=0; i<n; i++) {
        insertElement(hTable, keys[i]);
    }
    printTable();
    return 0;
}

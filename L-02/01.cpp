#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodetype{
  int key;
  struct nodetype *next;
 }NodeT;

 NodeT* create_node(int key){
   NodeT *p = (NodeT*)malloc(sizeof(NodeT));
   if (p==NULL){
     printf("eroare la alocarea memoriei \n");
     exit(1);
   }
   p->key = key;
   p->next = NULL;
   return p;
 }

 void insert_ord(NodeT **prm_rf, int cheie){
   NodeT *newNode = create_node(cheie);
   NodeT *current;

   current = *prm_rf;
   while(current->next != NULL && current->next->key < cheie)
   }





#include "list.h"
#include <stdio.h>

list_t* listNew(type_t t) {
   list_t* l = malloc(sizeof(list_t));
   l->type = t; // l->type es equivalente a (*l).type
   l->size = 0;
   l->first = NULL;
   return l;
}


void listAddFirst(list_t* l, void* data) {
   node_t* n = malloc(sizeof(node_t));
   switch(l->type) {
      case TypeFAT32:
        n->data = (void*) copy_fat32((fat32_t*) data);
        break;
      case TypeEXT4:
        n->data = (void*) copy_ext4((ext4_t*) data);
        break;
      case TypeNTFS:
        n->data = (void*) copy_ntfs((ntfs_t*) data);
        break;
   }
   n->next = l->first;
   l->first = n;
   l->size++;
}

//se asume: i < l->size
void* listGet(list_t* l, uint8_t i){
   node_t* n = l->first;
   for(uint8_t j = 0; j < i; j++)
      n = n->next;
   return n->data;
}

//se asume: i < l->size
void* listRemove(list_t* l, uint8_t i){
   node_t* tmp = NULL;
   void* data = NULL;
   if(i == 0){
      data = l->first->data;
      tmp = l->first;
      l->first = l->first->next;
   }else{
      node_t* n = l->first;
      for(uint8_t j = 0; j < i - 1; j++)
         n = n->next;
      data = n->next->data;
      tmp = n->next;
      n->next = n->next->next;
   }
   free(tmp);
   l->size--;
   return data;
}


void listDelete(list_t* l){
   node_t* n = l->first;
   while(n){
     node_t* tmp = n;
     n = n->next;
     switch(l->type) {
     case TypeFAT32:
       rm_fat32((fat32_t*) tmp->data);
       break;
     case TypeEXT4:
       rm_ext4((ext4_t*) tmp->data);
       break;
     case TypeNTFS:
       rm_ntfs((ntfs_t*) tmp->data);
       break;
     }
     free(tmp);
   }
   free(l);
}




void* listSwap(list_t* l, int p1, int p2){
   node_t* n = l->first;
   node_t* p1_node;
   node_t* p2_node;

   int len = l->size;

   if(len <= 1 || len < p1 || len < p2 || p1 == p2)
      return (void*) l->first;


   int i = 0;
   
   while(n) {
      if(i==p1)
         p1_node = n->data;
      if(i==p2)
         p2_node = n->data;
      n = n->next;
      i++;
   }

   if (p1_node && p2_node){
      node_t* tmp = p1_node;
      p1_node->data = p2_node->data;
      p2_node->data = tmp->data;
   }
   
   return (void*) l->first;
}

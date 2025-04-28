#include "list.h"
#include <stdio.h>

list_t* listDobleNew(type_t t){
    list_t* l =malloc(sizeof(list_t));
    l->type = t;
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    return l;
}

void listDobleAddFirts(list_t* l, void* data){
    node_t* n = malloc(sizeof(node_t));
    switch (l->type){
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

void listDobleAddLast(list_t* l, void* data){
    node_t* n = l->first;
    node_t* ultimo = malloc(sizeof(node_t));
    ultimo->data = data;

    node_t* prev;
    int i = 0;
    while(n){
        prev = n;
        if(n->next == NULL){
           n->next = ultimo;
           ultimo->prev = prev;
           prev->next = ultimo;
        }
        n=n->next;
    }
}

void* listDobleGet(list_t* l, uint8_t i){
      node_t* n = l->first;
   for(uint8_t j = 0; j < i; j++)
      n = n->next;
   return n->data; 
}

void* listDobleRemove(list_t* l, uint8_t i){
   node_t* tmp = NULL;
   void*  data = NULL;
   if (i == 0)
   {
      data = l->first->data;
      tmp  = l->first;
      l->first = l->first->next;
   }else
   {
      node_t* n = l->first;
      for(uint8_t j=0; j<i-1;j++)
         n = n->next;
      data = n->next->data;
      tmp = n->next;
      n->next = n->next->next; 
   }
   free(tmp);
   l->size--;
   return data;
}

void listDobleDelete(list_t* l){
   return;
}
#include "duplicar.h"
#include <stdlib.h>

void duplicar_pares1(LinkedNode *inicio)
{
  LinkedNode *atual = inicio;

  while (atual != NULL)
  {
    LinkedNode *next = atual->next;
    if (atual->data % 2 == 0)
    {
      LinkedNode *newNode = malloc(sizeof(LinkedNode));
      newNode->data = atual->data;
      newNode->next = next;
      atual->next = newNode;
      atual = atual->next;
    }
    atual = atual->next;
  }
}

void duplicar_pares2(DLinkedNode *inicio)
{
  DLinkedNode *atual = inicio;
  while (atual != NULL)
  {
    DLinkedNode *next = atual->next;
    if (atual->data % 2 == 0)
    {
      DLinkedNode *newNode = malloc(sizeof(DLinkedNode));
      newNode->data = atual->data;
      newNode->prev = atual;
      newNode->next = next;
      atual->next = newNode;
      if(next != NULL){
        next->prev = newNode;
      }
      atual = atual->next;
    }
    atual = atual->next;
  }
}
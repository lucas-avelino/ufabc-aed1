#include "insertionsort.h"
#include <stdio.h>

#include "insertionsort.h"

DLinkedNode *insertion_sort(DLinkedNode *inicio, int *comparacoes)
{

  (*comparacoes) = 0;
  if(inicio == NULL) return NULL;
  for (DLinkedNode *actual = inicio; actual != NULL; actual = actual->next)
  {

    DLinkedNode *comparePointer = actual->prev;
    while (comparePointer != NULL)
    {
      (*comparacoes)++;
      if(comparePointer->data <= comparePointer->next->data){
        break;
      }
      int temp = comparePointer->next->data;
      comparePointer->next->data = comparePointer->data;
      comparePointer->data = temp;
      
      comparePointer = comparePointer->prev;
    }
  }

  return inicio;
}

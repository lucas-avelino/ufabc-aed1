#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void contar(LinkedNode *inicio, int *qtd, int *soma)
{
  *qtd = 0;
  *soma = 0;
  LinkedNode *actualNode = inicio;
  for (*qtd = 0; actualNode != NULL; (*qtd) += 1)
  {
    (*soma) += actualNode->data;
    actualNode = actualNode->next;
  }
}

void imprimir1(LinkedNode *inicio)
{

  LinkedNode *actualNode = inicio;
  while (actualNode != NULL)
  {
    if (actualNode->next == NULL)
    {
      printf("%d\n", actualNode->data);
    }
    else
    {
      printf("%d ", actualNode->data);
    }
    actualNode = actualNode->next;
  }
}

void imprimirRec(LinkedNode *inicio, int isFirst)
{
  if(inicio->next == NULL && isFirst == 1){
    printf("%d\n", inicio->data);
    return;
  }
  if (inicio->next != NULL)
  {
    imprimirRec(inicio->next, 0);
    if (isFirst == 1)
    {
      printf("%d\n", inicio->data);
      return;
    }
  }
  printf("%d ", inicio->data);
}

void imprimir2(LinkedNode *inicio)
{
  imprimirRec(inicio, 1);
}
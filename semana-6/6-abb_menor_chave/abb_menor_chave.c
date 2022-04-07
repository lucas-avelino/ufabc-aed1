#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_string.h"

// Helper Functions

void printNode(NoArvore *raiz)
{
  printf("<NoArvore>[%p]'%s'\n", raiz, raiz != NULL ? raiz->chave : "NULL");
}

NoArvore *buscar(NoArvore *raiz, int chave)
{
  if (raiz == NULL)
    return NULL;

  if (chave == raiz->chave)
  {
    return raiz;
  }

  NoArvore *nextToSearch = chave > raiz->chave ? raiz->dir : raiz->esq;

  NoArvore *found = buscar(nextToSearch, chave);
  return found;
}

int menor_chave_comum(NoArvore *raiz1, NoArvore *raiz2)
{
  if (raiz1 == NULL)
    return -1;
  int smallestKey = -1;

  NoArvore *nodeOnRaiz2 = buscar(raiz2, raiz1->chave);

  if (nodeOnRaiz2 != NULL)
  {
    smallestKey = nodeOnRaiz2->chave;
  }

  if (raiz1->esq != NULL || raiz1->dir != NULL)
  {
    int smallestLeft = menor_chave_comum(raiz1->esq, raiz2);
    int smallestRight = menor_chave_comum(raiz1->dir, raiz2);

    smallestKey = smallestKey == -1 ? __INT_MAX__ : smallestKey;
    smallestLeft = smallestLeft == -1 ? __INT_MAX__ : smallestLeft;
    smallestRight = smallestRight == -1 ? __INT_MAX__ : smallestRight;

    smallestKey = smallestKey < smallestLeft && smallestKey < smallestRight
                      ? smallestKey
                      : (smallestRight < smallestLeft
                             ? smallestRight
                             : smallestLeft);

    smallestKey = smallestKey == __INT_MAX__ ? -1 : smallestKey;
  }

  return smallestKey;
}

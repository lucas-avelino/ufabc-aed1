#include <stdio.h>
#include <stdlib.h>
#include "abb_sucessor_antecessor.h"

NoArvore *createTreeWithIntArray(int arr[], int arraySize)
{
  NoArvore *raiz = malloc(sizeof(NoArvore) * arraySize);
  raiz->chave = arr[0];
  for (int i = 1; i < arraySize; i++)
  {
    NoArvore *actual = raiz;
    NoArvore *prev = raiz;
    raiz[i] = (NoArvore){arr[i], NULL, NULL};

    while (actual != NULL && arr[i] != actual->chave)
    {
      prev = actual;
      if (arr[i] < actual->chave)
        actual = actual->esq;
      else
        actual = actual->dir;
    }

    if (prev->chave > arr[i])
    {
      prev->esq = &raiz[i];
    }
    else
    {
      prev->dir = &raiz[i];
    }
  }

  return raiz;
}

int main(int argc, char const *argv[])
{
  NoArvore *raiz = createTreeWithIntArray((int[]){120, 110, 150, 250, 200, 100, 2, 90, 10, 100, 20, 160}, 12);
  printf("->> createTreeWithIntArray Done with raiz= %d esq= %d dir= %d\n", raiz->chave, raiz->esq->chave, raiz->dir->chave);
  int suc = sucessor(raiz, 60);
  printf("%d\n", suc);
  return 0;
}

// I 120 I 110 I 150 I 250 I 200 I 1 I 2 I 90 I 10 I 100 I 20 I 160
#include <stdlib.h>
#include "abb_chaves_comuns.h"

int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2)
{
  if(raiz1 == NULL) return 0;
  int numberOfRepeats = 0;

  NoArvore *actual = raiz2;
  while (actual != NULL && actual->chave != raiz1->chave)
  {
    if (actual->chave > raiz1->chave)
    {
      actual = actual->esq;
    }else{
      actual = actual->dir;
    }
  }

  if(actual != NULL && actual->chave == raiz1->chave){
    numberOfRepeats++;
  }

  if (raiz1->esq != NULL || raiz1->dir != NULL)
  {
    numberOfRepeats += qtd_chaves_comuns(raiz1->esq, raiz2) + qtd_chaves_comuns(raiz1->dir, raiz2);
  }

  return numberOfRepeats;
}
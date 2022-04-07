#include <stdlib.h>
#include "abb_menor_maior.h"

int menor(NoArvore *raiz)
{
  if (raiz == NULL)
    return -1;

  NoArvore *actual = raiz;

  while (actual->esq != NULL)
  {

    actual = actual->esq;
  }

  return actual->chave;
}

int maior(NoArvore *raiz)
{
  if (raiz == NULL)
    return -1;

  NoArvore *actual = raiz;

  while (actual->dir != NULL)
  {

    actual = actual->dir;
  }

  return actual->chave;
}

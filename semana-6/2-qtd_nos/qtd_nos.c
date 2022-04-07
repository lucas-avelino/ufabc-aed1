#include <stdlib.h>
#include "qtd_nos.h"

int numero_nos(NoArvore *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int numero_nos_folha(NoArvore *raiz)
{
  if (raiz == NULL)
    return 0;

  if (raiz->esq == NULL && raiz->dir == NULL)
    return 1;

  return numero_nos_folha(raiz->esq) + numero_nos_folha(raiz->dir);
}

int numero_nos_internos(NoArvore *raiz)
{
  if (raiz == NULL)
    return 0;

  if (raiz->esq != NULL || raiz->dir != NULL)
    return numero_nos_internos(raiz->esq) + numero_nos_internos(raiz->dir) + 1;

  return 0;
}
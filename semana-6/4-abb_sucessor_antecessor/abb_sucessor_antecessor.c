#include <stdlib.h>
#include "abb_sucessor_antecessor.h"

int menor(NoArvore *raiz)
{
  if (raiz == NULL)
    return -1;

  NoArvore *actual = raiz;

  while (actual->esq != NULL)
    actual = actual->esq;

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

NoArvore *findParent(NoArvore *raiz, int chave)
{
  NoArvore *actual = raiz;
  NoArvore *prev = raiz;

  while (actual != NULL && chave != actual->chave)
  {
    prev = actual;
    if (chave < actual->chave)
      actual = actual->esq;
    else
      actual = actual->dir;
  }
  if (actual == prev)
  {
    return NULL;
  }

  return prev;
}

NoArvore *find(NoArvore *raiz, int chave)
{
  if (raiz == NULL || chave == raiz->chave)
    return raiz;
  if (chave < raiz->chave)
    return find(raiz->esq, chave);
  else
    return find(raiz->dir, chave);
}

int sucessor(NoArvore *raiz, int chave)
{
  NoArvore *item = find(raiz, chave);
  if (raiz == NULL || item == NULL)
  {
    return -1;
  }

  if (item->dir != NULL)
  {
    return menor(item->dir);
  }

  NoArvore *itemParent = findParent(raiz, chave);
  if(itemParent == NULL){
    return -1;
  }

  int prevKey = chave;
  int smallKey = menor(itemParent->dir);

  while (smallKey <= chave)
  {
    if (prevKey < itemParent->chave)
    {
      return itemParent->chave;
    }

    prevKey = itemParent->chave;
    itemParent = findParent(raiz, itemParent->chave);

    if (itemParent == NULL)
    {
      return -1;
    }
    smallKey = menor(itemParent->dir);
  }

  return itemParent->chave;
}

int antecessor(NoArvore *raiz, int chave)
{
  NoArvore *item = find(raiz, chave);
  if (raiz == NULL || item == NULL)
  {
    return -1;
  }

  if (item->esq != NULL)
  {
    return maior(item->esq);
  }

  NoArvore *itemParent = findParent(raiz, chave);
  if(itemParent == NULL){
    return -1;
  }
  int prevKey = chave;
  int biggestKey = maior(itemParent->esq);

  while (biggestKey >= chave)
  {
    if (prevKey > itemParent->chave)
    {
      return itemParent->chave;
    }

    prevKey = itemParent->chave;
    itemParent = findParent(raiz, itemParent->chave);

    if (itemParent == NULL)
    {
      return -1;
    }
    biggestKey = maior(itemParent->esq);
  }

  return itemParent->chave;
}
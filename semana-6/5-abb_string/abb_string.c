#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb_string.h"

// Helper Functions

void printNode(NoArvore *raiz)
{
  printf("<NoArvore>[%p]'%s'\n", raiz, raiz != NULL ? raiz->chave : "NULL");
}

NoArvore *menor(NoArvore *raiz)
{
  if (raiz == NULL)
    return NULL;

  NoArvore *actual = raiz;

  while (actual->esq != NULL)
    actual = actual->esq;

  return actual;
}

NoArvore *buscarPai(NoArvore *raiz, char *chave)
{
  if (raiz == NULL)
  {
    return NULL;
  }

  NoArvore *actual = raiz;
  NoArvore *prev = raiz;

  while (actual != NULL && strcmp(chave, actual->chave) != 0)
  {
    prev = actual;
    int strCompare = strcmp(chave, actual->chave);
    if (strCompare < 0)
      actual = actual->esq;
    else if (strCompare > 0)
      actual = actual->dir;
    else
    {
      return prev;
    }
  }

  if (actual == prev)
  {
    return NULL;
  }

  return prev;
}

//

NoArvore *buscar(NoArvore *raiz, char *chave)
{
  if (raiz == NULL)
    return NULL;

  int strCompare = strcmp(chave, raiz->chave);

  if (strCompare == 0)
  {
    return raiz;
  }

  NoArvore *nextToSearch = strCompare > 0 ? raiz->dir : raiz->esq;

  NoArvore *found = buscar(nextToSearch, chave);
  return found;
}

NoArvore *inserir(NoArvore *raiz, char *chave_nova)
{
  if (raiz == NULL)
  {
    NoArvore *newNode = malloc(sizeof(NoArvore));
    char *text = malloc(sizeof(char) * 100); // strcpy(chave_nova)
    strcpy(text, chave_nova);
    newNode->chave = text;
    newNode->esq = NULL;
    newNode->dir = NULL;

    return newNode;
  }

  NoArvore *actual = raiz;
  while (actual != NULL)
  {
    int strCompare = strcmp(chave_nova, actual->chave);

    if (strCompare == 0)
    {
      return raiz;
    }
    NoArvore *temp = strCompare > 0 ? actual->dir : actual->esq;

    if (temp == NULL && strCompare > 0)
    {
      NoArvore *newNode = malloc(sizeof(NoArvore));
      char *text = malloc(sizeof(char) * 100);
      strcpy(text, chave_nova);
      *newNode = (NoArvore){text, NULL, NULL};
      actual->dir = newNode;
      break;
    }

    if (temp == NULL && strCompare <= 0)
    {
      NoArvore *newNode = malloc(sizeof(NoArvore));
      char *text = malloc(sizeof(char) * 100);
      strcpy(text, chave_nova);
      *newNode = (NoArvore){text, NULL, NULL};
      actual->esq = newNode;
      break;
    }

    actual = temp;
  }

  return raiz;
}

NoArvore *sucessor(NoArvore *raiz, char *chave)
{
  NoArvore *item = buscar(raiz, chave);
  if (raiz == NULL || item == NULL)
  {
    return NULL;
  }

  if (item->dir != NULL)
  {
    return menor(item->dir);
  }

  NoArvore *itemParent = buscarPai(raiz, chave);
  if (itemParent == NULL)
  {
    return NULL;
  }

  char *prevKey = chave;
  char *smallKey = menor(itemParent->dir)->chave;

  while (smallKey <= chave)
  {
    if (prevKey < itemParent->chave)
    {
      return itemParent;
    }

    prevKey = itemParent->chave;
    itemParent = buscarPai(raiz, itemParent->chave);

    if (itemParent == NULL)
    {
      return NULL;
    }
    smallKey = menor(itemParent->dir)->chave;
  }

  return itemParent;
}

NoArvore *remover(NoArvore *raiz, char *chave)
{
  NoArvore *toRemove = buscar(raiz, chave);
  NoArvore *toRemoveParent = buscarPai(raiz, chave);

  if (toRemoveParent == NULL) // é a raiz
  {
    if (toRemove->dir == NULL && toRemove->esq == NULL) // Se nó é folha
    {
      raiz = NULL;
    }
    else if (!(toRemove->dir != NULL && toRemove->esq != NULL))
    {
      raiz = toRemove->dir != NULL ? toRemove->dir : toRemove->esq;
    }
    else if (toRemove->dir != NULL && toRemove->esq != NULL)
    {
      NoArvore *suc = sucessor(raiz, chave);
      NoArvore *sucParent = buscarPai(raiz, suc->chave);

      int strCompare = strcmp(sucParent->chave, suc->chave);
      printf("%d %p\n", strCompare, sucParent);
      if (strCompare < 0)
        sucParent->dir = NULL;
      else
        sucParent->esq = NULL;

      raiz = suc;

      if (suc->esq == NULL)
        suc->esq = toRemove->esq;
      if (suc->dir == NULL)
        suc->dir = toRemove->dir;
    }
  }
  else
  {
    int toRemoveParentStrCompare = strcmp(toRemoveParent->chave, chave);

    // Se nó é folha
    if (toRemove->dir == NULL && toRemove->esq == NULL)
    {
      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = NULL;
      }
      else
      {
        toRemoveParent->esq = NULL;
      }
    }
    // Se nó tem um filho
    if (toRemove->dir != NULL && toRemove->esq == NULL)
    {
      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = toRemove->dir;
      }
      else
      {
        toRemoveParent->esq = toRemove->dir;
      }
    }

    // Se nó tem um filho
    if (toRemove->dir == NULL && toRemove->esq != NULL)
    {
      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = toRemove->esq;
      }
      else
      {
        toRemoveParent->esq = toRemove->esq;
      }
    }

    // Se nó tem dois filhos
    if (toRemove->dir != NULL && toRemove->esq != NULL)
    {
      NoArvore *suc = sucessor(raiz, chave);
      NoArvore *sucParent = buscarPai(raiz, suc->chave);

      int strCompare = strcmp(sucParent->chave, suc->chave);
      if (strCompare < 0)
      {
        sucParent->dir = NULL;
      }
      else
      {
        sucParent->esq = NULL;
      }

      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = suc;
      }
      else
      {
        toRemoveParent->esq = suc;
      }

      if (suc->esq == NULL)
        suc->esq = toRemove->esq;
      if (suc->dir == NULL)
        suc->dir = toRemove->dir;
    }
  }

  toRemove->dir = NULL;
  toRemove->esq = NULL;
  liberar_arvore(toRemove);
  return raiz;
}

void liberar_arvore(NoArvore *raiz)
{
  if (raiz == NULL)
    return;

  if (raiz->esq != NULL || raiz->dir != NULL)
  {
    liberar_arvore(raiz->dir);
    liberar_arvore(raiz->esq);
  }
  free(raiz->chave);
  free(raiz);
}
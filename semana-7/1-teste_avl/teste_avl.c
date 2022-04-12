#include <stdio.h>
#include <stdlib.h>
#include "teste_avl.h"

int alturaRec(NoArvore *n)
{
  if (n == NULL)
  {
    return 0;
  }

  int altEsquerda = alturaRec(n->esq);
  int altDiretira = alturaRec(n->dir);

  return 1 + (altEsquerda > altDiretira ? altEsquerda : altDiretira);
}

NoArvore *allocNode(int valor, int altura)
{
  NoArvore *newNode = malloc(sizeof(NoArvore));
  newNode->altura = altura;
  newNode->chave = valor;
  newNode->esq = NULL;
  newNode->dir = NULL;
  return newNode;
}

int testAVL(NoArvore *raiz, int valor)
{
  if (raiz == NULL)
    return 1;

  int result = alturaRec(raiz->esq) - alturaRec(raiz->dir);
  result = result < 0 ? result * -1 : result; // Modulo

  NoArvore *nextToSearch = valor > raiz->chave ? raiz->dir : raiz->esq;
  int resultRec = testAVL(nextToSearch, valor);

  if (result > 1)
  {
    printf("[No desbalanceado: %d]\n", raiz->chave);
  }

  return result <= 1 && resultRec == 1 ? 1 : 0;
}

NoArvore *inserir(NoArvore *raiz, int valor)
{
  int altura = 1;
  if (raiz == NULL)
  {
    raiz = allocNode(valor, altura);
  }
  else
  {
    NoArvore *actual = raiz;
    while (actual != NULL)
    {
      altura++;
      if (actual->chave == valor)
      {
        break;
      }
      NoArvore *temp = valor > actual->chave ? actual->dir : actual->esq;

      if (temp == NULL && valor > actual->chave)
      {
        actual->dir = allocNode(valor, altura);
        break;
      }

      if (temp == NULL && valor < actual->chave)
      {
        actual->esq = allocNode(valor, altura);
        break;
      }

      actual = temp;
    }
  }
  printf("Inserir:%d\n", valor);
  int result = testAVL(raiz, valor);
  if (result == 1)
  {
    printf("[Ja esta balanceada]\n");
  }
  return raiz;
}

int altura(NoArvore *n)
{
  return alturaRec(n) - 1;
}

void liberar_arvore(NoArvore *raiz)
{
  if (raiz == NULL)
    return;
  liberar_arvore(raiz->esq);
  liberar_arvore(raiz->dir);
  printf("%d ", raiz->chave);
  free(raiz);
}
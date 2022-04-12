#include <stdio.h>
#include <stdlib.h>
#include "teste_avl.h"

int main()
{
  NoArvore *raiz = NULL;
  char operacao;
  do
  {
    scanf(" %c", &operacao);
    switch (operacao)
    {
    case 'I':
    {
      int valor;
      scanf("%d", &valor);
      raiz = inserir(raiz, valor);
      break;
    }
    case 'A':
    {
      printf("A=%d\n", altura(raiz));
      break;
    }
    case 'P':
    {
      printf("[");
      liberar_arvore(raiz);
      printf("]\n");
      break;
    }
    }
  } while (operacao != 'P');

  return 0;
}
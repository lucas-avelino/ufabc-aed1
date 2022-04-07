#include <stdio.h>
#include <stdlib.h>
#include "abb_string.h"

int main(int argc, char const *argv[])
{
  // printf("testeeeee\n");
  // NoArvore *raiz = (NoArvore *)malloc(sizeof(NoArvore));
  // char *text = malloc(sizeof(char) * 100); // strcpy(chave_nova)
  // strcpy(text, "dados");
  // *raiz = (NoArvore){text, NULL, NULL};

  // NoArvore *raiz = inserir(NULL, "dados");

  NoArvore *raiz = inserir(NULL, "dados");
  inserir(raiz, "algoritmos");
  inserir(raiz, "estruturas");
  inserir(raiz, "eestruturas");
  inserir(raiz, "professor");
  printNode(raiz);
  NoArvore *noAlg = buscar(raiz, "algoritmos");
  printf("Post buscar\n");

  printf("raiz: ");
  printNode(raiz);
  printf("noAlg: ");
  printNode(noAlg);

  raiz = remover(raiz, "dados");
  printf("Removed\n");

  NoArvore *estruturas = buscar(raiz, "professor");
  printf("Found: [%p]'%s'\n", estruturas, estruturas != NULL ? estruturas->chave : "");

  return 0;
}

/**

I dados
I algoritmos
I estruturas
I professor
R estruturas
R algoritmos
B estruturas
B professor
S

 */
#include <stdio.h>
#include <stdlib.h>
#include "abb_chaves_comuns.h"

int main(int argc, char const *argv[])
{
  NoArvore *a = malloc(sizeof(NoArvore) * 3);
  a[2] = (NoArvore){3, NULL, NULL};
  a[1] = (NoArvore){1, NULL, NULL};
  a[0] = (NoArvore){2, &a[1], &a[2]};

  NoArvore *b = malloc(sizeof(NoArvore) * 3);
  b[2] = (NoArvore){3, NULL, NULL};
  // b[1] = (NoArvore){1, NULL, NULL};
  b[0] = (NoArvore){2, NULL, &b[2]};
  
  printf("teste");
  int result = qtd_chaves_comuns(a, b);
  printf("%d\n", result);
  return 0;
}
#include <stdio.h>
// #include "funcao_param_referencia.h"

void funcao(int a, int b, int *resultado)
{
  (*resultado) = 0;
  for (int i = 1; i <= a; i++)
  {
    int somatorioInterno = 0;
    for (int j = 1; j <= b; j++)
    {
      (*resultado) = (*resultado) + 5 * i * (i * j + 10);
    }
  }
}

void main()
{
  int valor = 0;

  printf("%d\n", valor);
  funcao(2, 3, &valor);

  printf("%d\n", valor);
}

// 5 2

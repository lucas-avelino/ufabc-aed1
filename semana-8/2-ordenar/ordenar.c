#include "ordenar.h"
#include "funcao_comparar.h"

void ordenar_vetor(ItemVetor v[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < n ; j++)
    {
      if (comparar(v[j-1], v[j]) > 0)
      {
        ItemVetor aux = v[j - 1];
        v[j -1] = v[j];
        v[j] = aux;
      }
    }
  }
}
#include "qtd_discos.h"
#include <stdlib.h>

// "Modelo_C11"

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante)
{
  (*quantidade_por_fabricante) = malloc(sizeof(int) * 4);
  for (int i = 0; i < n_discos; i++)
  {
    (*quantidade_por_fabricante)[discos[i][7] - 65] += 1;
  }
}
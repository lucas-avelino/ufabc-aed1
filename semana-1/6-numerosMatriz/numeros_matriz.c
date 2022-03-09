#include "numeros_matriz.h"

void remover_numeros_matriz(int l, int c, int n_linhas, int n_colunas, int m[n_linhas][n_colunas])
{
  int selectedValue = m[l][c];
  m[l][c] = 0;

  if (l + 1 < n_linhas && m[l + 1][c] == selectedValue)
    remover_numeros_matriz(l + 1, c, n_linhas, n_colunas, m);

  if (l - 1 >= 0 && m[l - 1][c] == selectedValue)
    remover_numeros_matriz(l - 1, c, n_linhas, n_colunas, m);

  if (c + 1 < n_colunas && m[l][c + 1] == selectedValue)
    remover_numeros_matriz(l, c + 1, n_linhas, n_colunas, m);

  if (c - 1 >= 0 && m[l][c - 1] == selectedValue)
    remover_numeros_matriz(l, c - 1, n_linhas, n_colunas, m);
    
}
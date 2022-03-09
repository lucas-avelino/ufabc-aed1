#include <stdio.h>
// #include "qtd_palavras_frase.h"

int main()
{
  imprimir_qtd_palavras("Algoritmos e Estruturas de Dados I. Nessa disciplina, serao vistas estruturas de dados como listas, pilhas, filas e arvores. Tambem serao vistos algoritmos de busca e ordenacao.");
}

void imprimir_qtd_palavras(char texto[])
{
  int qtdPalavras = 1;

  for (int i = 0; texto[i] != '\0'; i++)
  {
    if (texto[i] == ' ' && (texto[i+1] >= 'a' && texto[i+1] <= 'z') || (texto[i+1] >= 'A' && texto[i+1] <= 'Z'))
    {
      qtdPalavras++;
    }
    if (texto[i] == '.')
    {
      printf("%d\n", qtdPalavras);
      qtdPalavras = 0;
    }
  }
}

#include "qtd_digitos.h"

int quantidade_digitos(int numero)
{
  int quantidadeDeDigitos = 1;

  while (numero > 9){
    numero = numero / 10;
    quantidadeDeDigitos++;
  }
  
  return quantidadeDeDigitos;
}
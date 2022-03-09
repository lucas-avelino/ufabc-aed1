#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"
#include <string.h>

int main(int argc, char const *argv[])
{
  char *frase = malloc( 100 * sizeof(char));
  strcat(frase, "Uma empresa que vende computadores trabalha com tres modelos: computador A, computador B e computador C.");
  char *palavra1 = "computador";
  char *palavra2 = "modelo";
  // deslocate(frase, 49, -3);
  substituir_palavra(frase, palavra1, palavra2);

  printf("%s\n", frase);
}
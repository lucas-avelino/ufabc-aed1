#include <stdio.h>
#include <stdlib.h>
#include "fracoes.h"

int main(int argc, char const *argv[])
{
  Fracao f1 = {1, 2};
  Fracao f2 = {2, 2};
  Fracao f3 = somar(f1, f2);

  printf("%d/%d\n", f3.numerador, f3.denominador);

  Fracao f4 = somar_vetor((Fracao[]){
                              {10, 1},
                              {8, 1},
                              {5, 15},
                              {1, 1},
                              {60, 12},
                              {2, 3}},
                          6);

  printf("%d/%d\n", f4.numerador, f4.denominador);
  return 0;
}

/**
 * 6
{10, 1},
{8, 1},
{5, 15},
{1, 1},
{60, 12},
{2, 3},
**/
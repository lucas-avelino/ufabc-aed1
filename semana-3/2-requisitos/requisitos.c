#include <stdlib.h>
#include "requisitos.h"

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd)
{
  Disciplina *disciplinaAtual = disciplina->requisito;
  (*qtd) = 0;
  while(disciplinaAtual != NULL){
    disciplinaAtual = disciplinaAtual->requisito;
    (*qtd)+=1;
  }

  return disciplinaAtual;
}
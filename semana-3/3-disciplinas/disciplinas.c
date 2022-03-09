#include <stdlib.h>
#include "disciplinas.h"

int compareStrings(char *string1, char *string2)
{
  int i;
  for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++)
  {
    if (string1[i] > string2[i])
    {
      return 1;
    }
    if (string1[i] < string2[i])
    {
      return -1;
    }
  }
  if (string2[i] == '\0')
  {
    return 1;
  }
  else
  {
    return -1;
  }

  return 0;
}

void insere_disciplina(Curso *curso, Disciplina *nova_disciplina)
{
  Disciplina *disciplinaFinalCurso = curso->ultima_disciplina;

  if (compareStrings(disciplinaFinalCurso->nome, nova_disciplina->nome) == -1)
  {
    nova_disciplina->requisito = disciplinaFinalCurso;

    curso->ultima_disciplina = nova_disciplina;
    return;
  }

  Disciplina *disciplinaAtual = disciplinaFinalCurso;

  while (disciplinaAtual->requisito != NULL && compareStrings(disciplinaAtual->requisito->nome, nova_disciplina->nome) == 1)
  {
    disciplinaAtual = disciplinaAtual->requisito;
  }

  Disciplina *aux = disciplinaAtual->requisito;
  disciplinaAtual->requisito = nova_disciplina;
  nova_disciplina->requisito = aux;
}

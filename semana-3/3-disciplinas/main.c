#include <stdio.h>
#include <stdlib.h>
#include "disciplinas.h"

int main(int argc, char const *argv[])
{
  Disciplina *d = malloc(sizeof(Disciplina) * 3);

  d[0] = (Disciplina){1, "Disciplina", 1, NULL};
  d[1] = (Disciplina){1, "Disciplina10", 1, NULL};
  d[2] = (Disciplina){1, "Disciplina20", 1, NULL};
  d[2].requisito = &d[1];
  d[1].requisito = &d[0];

  Curso *c = malloc(sizeof(Curso));

  c->ultima_disciplina = &d[2];

  Disciplina *d_nova = malloc(sizeof(Disciplina));

  *d_nova = (Disciplina){1, "Disciplina30", 1, NULL};

  Disciplina *disciplinaAtual = c->ultima_disciplina;

  while (disciplinaAtual->requisito != NULL)
  {
    printf("%s\n", disciplinaAtual->nome);
    disciplinaAtual = disciplinaAtual->requisito;
  }
  printf("%s\n", disciplinaAtual->nome);


  printf("____insere_disciplina____\n");
  insere_disciplina(c, d_nova);

  disciplinaAtual = c->ultima_disciplina;

  while (disciplinaAtual->requisito != NULL)
  {
    printf("%s\n", disciplinaAtual->nome);
    disciplinaAtual = disciplinaAtual->requisito;
  }
  printf("%s\n", disciplinaAtual->nome);

  return 0;
}

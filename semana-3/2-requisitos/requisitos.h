#ifndef Fracao_H // guardas de cabeçalho, impedem inclusões cíclicas
#define Fracao_H

typedef struct Disciplina Disciplina;
struct Disciplina
{
  int cod;
  char *nome;
  int creditos;
  Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd);

#endif

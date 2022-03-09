#ifndef Disciplina_H // guardas de cabeçalho, impedem inclusões cíclicas
#define Disciplina_H

typedef struct Disciplina Disciplina;
struct Disciplina
{
  int cod;
  char *nome;
  int creditos;
  Disciplina *requisito;
};

typedef struct Curso Curso;
struct Curso
{
  int cod_curso;
  char *nome_curso;
  Disciplina *ultima_disciplina;
};

#endif

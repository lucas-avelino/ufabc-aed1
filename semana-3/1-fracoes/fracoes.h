#ifndef Fracao_H // guardas de cabeçalho, impedem inclusões cíclicas
#define Fracao_H

typedef struct Fracao Fracao;

struct Fracao
{
  int numerador, denominador;
};

Fracao somar(Fracao f1, Fracao f2);

Fracao somar_vetor(Fracao f[], int n_fracoes);

Fracao multiplicar(Fracao f1, Fracao f2);

Fracao multiplicar_vetor(Fracao f[], int n_fracoes);

#endif

#include "fracoes.h"

int maior_divisor_comum(int a, int b)
{

  while (a != 0)
  {
    int restoDaDivisao = b % a;
    b = a;
    a = restoDaDivisao;
  }

  return b;
}

Fracao simplifica_fracao(Fracao f)
{
  int maiorDivisorComum = maior_divisor_comum(f.numerador, f.denominador);
  return (Fracao){f.numerador / maiorDivisorComum, f.denominador / maiorDivisorComum};
}

Fracao somar(Fracao f1, Fracao f2)
{
  Fracao f = {(f1.numerador * f2.denominador) + (f1.denominador * f2.numerador), (f1.denominador * f2.denominador)};
  return simplifica_fracao(f);
}

Fracao somar_vetor(Fracao f[], int n_fracoes)
{
  Fracao soma = f[0];
  for (int i = 1; i < n_fracoes; i++)
  {
    soma = somar(soma, f[i]);
  }

  return soma;
}

Fracao multiplicar(Fracao f1, Fracao f2)
{
  return simplifica_fracao((Fracao){f1.numerador * f2.numerador, f1.denominador * f2.denominador});
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes)
{
  Fracao resultado = f[0];
  for (int i = 1; i < n_fracoes; i++)
  {
    resultado = multiplicar(resultado, f[i]);
  }

  return resultado;
}

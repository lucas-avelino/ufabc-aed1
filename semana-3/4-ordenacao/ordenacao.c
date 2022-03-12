#include "ordenacao.h"

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
  if (string2[i] == '\0' && string1[i] !=  '\0')
  {
    return 1;
  }
  else if(string1[i] == '\0' && string2[i] !=  '\0')
  {
    return -1;
  }

  return 0;
}

int verificar_ordenacao(DiscoVoador *discos, int n_discos)
{
  char rule1 = 1;
  char rule2 = 1;
  char rule3 = 1;
  char rule4 = 1;

  for (int i = 1; i < n_discos; i++)
  {
    int modelCompare = compareStrings(discos[i - 1].modelo, discos[i].modelo);
    int planetCompare = compareStrings(discos[i - 1].planeta, discos[i].planeta);
    int autonomyCompare = discos[i - 1].autonomia > discos[i].autonomia ? 1 : (discos[i - 1].autonomia < discos[i].autonomia ? -1 : 0);

    if (modelCompare == -1)
    {
      rule2 = 0;
    }
    if (modelCompare == 1)
    {
      rule1 = 0;
    }
    if (planetCompare == 1 || (planetCompare == 0 && autonomyCompare == -1))
    {
      rule3 = 0;
    }
    if (autonomyCompare == 1 || (autonomyCompare == 0 && planetCompare == 1) || (autonomyCompare == 0 && planetCompare == 0 && modelCompare == 1))
    {
      rule4 = 0;
    }
  }

  if (rule1 == 1)
    return 1;
  if (rule2 == 1)
    return 2;
  if (rule3 == 1)
    return 3;
  if (rule4 == 1)
    return 4;
  return 0;
}

/*
1: ordenação pelo modelo (ordem lexicográfica crescente);
2: ordenação pelo modelo (ordem lexicográfica decrescente);
3: ordenação pelo planeta (ordem lexicográfica crescente) e, em caso de empate, pela autonomia (ordem decrescente);
4: ordenação pelo autonomia (ordem crescente) e, em caso de empate, pelo planeta (ordem lexicográfica crescente) e, em caso de empate em autonomia e planeta, ordenação pelo modelo (ordem lexicográfica crescente).
*/
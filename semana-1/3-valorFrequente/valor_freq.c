#include "valor_freq.h"

int valor_frequente(int v[], int n)
{
  int actualOccurrences = 0;
  int actualOccurrenceIndex = 0;

  int biggestOccurrences = 0;
  int biggestOccurrenceIndex = 0;

  for (int i = 0; i < n; i++)
  {
    actualOccurrences = 0;
    actualOccurrenceIndex = i;
    for (int j = i; j < n; j++)
    {
      if (v[j] == v[i])
        actualOccurrences++;
    }

    if (actualOccurrences > biggestOccurrences)
    {
      biggestOccurrenceIndex = actualOccurrenceIndex;
      biggestOccurrences = actualOccurrences;
    }
  }
  return v[biggestOccurrenceIndex];
}
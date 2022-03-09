#include "vetor.h"
#include <stdlib.h>

int *expandir_vetor(const int *vector, int compactSize, int *expandedVectorSize)
{
  int actualIndex = 0;
  *expandedVectorSize = 0;
  for (int i = 1; i < compactSize; i += 2) *expandedVectorSize += vector[i];

  int *expandedVector = malloc((*expandedVectorSize) * sizeof(int));

  for (int i = 0; i < compactSize; i += 2)
  {
    for (int j = 0; j < vector[i + 1]; j++)
    {
      expandedVector[j + actualIndex] = vector[i];
    }
    actualIndex += vector[i + 1];
  }

  return expandedVector;
}
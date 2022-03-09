#include <stdio.h>

int main()
{
  int numberOfItems = 0;
  scanf("%d", &numberOfItems);

  int items[numberOfItems];
  int biggestSeqStart = 0;
  int biggestSeqEnd = 0;
  int actualSeqStart = 0;
  int actualSeqEnd = 0;

  for (int i = 0; i < numberOfItems; i++)
  {
    scanf("%d", &items[i]);
  }

  for (int i = 1; i < numberOfItems; i++)
  {
    if (items[i - 1] < items[i])
    {
      actualSeqEnd = i;
    }
    else
    {
      actualSeqStart = actualSeqEnd = i;
    }

    // se sequesncia atual > que a maior encontrada
    if (biggestSeqEnd - biggestSeqStart < actualSeqEnd - actualSeqStart)
    {
      biggestSeqStart = actualSeqStart;
      biggestSeqEnd = actualSeqEnd;
    }
  }

  for (int i = biggestSeqStart; i <= biggestSeqEnd; i++)
  {
    printf("%d ", items[i]);
  }
}
#include <stdio.h>
#include <stdlib.h>

int ppow(int base, int expoent)
{
  int result = 1;

  while (expoent > 0)
  {
    result *= base;
    expoent--;
  }

  return result;
}

int main(int argc, char const *argv[])
{
  int size = 15;
  int scores[size][2];
  for (int i = 0; i < size; i++)
  {
    scanf("%d %d\n", &scores[i][0], &scores[i][1]);
  }

  char winners[4];

  int pointerA = 0, pointerB = size, actual = (size - 1);
  int qtdNodesAcumulados = 0;
  int prevMin = (size - 1);
  for (int i = 0; i < 3; i++)
  {
    printf("qtdNodesAcumulados:%d\n", qtdNodesAcumulados);

    int quantityOfNodes = ppow(2, i);
    printf("quantityOfNodes:%d\n", quantityOfNodes);

    int quantityOfNodesNextStep = quantityOfNodes * 2;
    printf("quantityOfNodesNextStep:%d\n", quantityOfNodesNextStep);

    int min = prevMin - (quantityOfNodesNextStep);
    printf("min:%d\n", min);

    int posRelativeToPrevMin = actual - prevMin;
    printf("posRelativeToPrevMin:%d\n", posRelativeToPrevMin);

    int posRelativeToNewMin = posRelativeToPrevMin * 2;
    printf("posRelativeToNewMin:%d\n", posRelativeToNewMin);
    printf("--> SCORE: %dX%d\n", scores[actual][0], scores[actual][1]);

    int winnerPos = min + posRelativeToNewMin + (scores[actual][0] > scores[actual][1] ? 0 : 1);
    printf("winnerPos:%d\n", winnerPos);

    qtdNodesAcumulados += quantityOfNodes;
    prevMin = min;
    actual = winnerPos;
  }
  char result = (actual * 2) + (scores[actual][0] > scores[actual][1] ? 0 : 1);
  printf("--> [%d] SCORE: %dX%d result = %d\n", actual, scores[actual][0], scores[actual][1], result);
  printf("%C\n", (char)(result + 65));

  return 0;
}
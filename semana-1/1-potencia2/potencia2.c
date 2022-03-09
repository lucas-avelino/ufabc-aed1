#include <stdio.h>

int main()
{
  int numberOfItems = 0;
  int quantityOfTwoPow = 0;

  scanf("%d", &numberOfItems);

  while ((numberOfItems--) > 0)
  {
    int number = 0;
    scanf("%d", &number);

    while (number % 2 == 0)
      number /= 2;

    if (number == 1)
      quantityOfTwoPow++;
  }

  printf("%d\n", quantityOfTwoPow);
}
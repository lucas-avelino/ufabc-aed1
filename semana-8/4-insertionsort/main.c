#include <stdio.h>
#include <stdlib.h>
#include "insertionsort.h"

int main()
{
  DLinkedNode *list = malloc(sizeof(DLinkedNode) * 5);
  list[0] = (DLinkedNode){55, NULL, &list[1]};
  list[1] = (DLinkedNode){44, &list[0], &list[2]};
  list[2] = (DLinkedNode){33, &list[1], &list[3]};
  list[3] = (DLinkedNode){22, &list[2], &list[4]};
  list[4] = (DLinkedNode){11, &list[3], NULL};

  int compare = 0;
  insertion_sort(list, &compare);

  return 0;
}
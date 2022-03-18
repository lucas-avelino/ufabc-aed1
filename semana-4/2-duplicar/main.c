#include <stdio.h>
#include <stdlib.h>
#include "duplicar.h"

int main(int argc, char const *argv[])
{
  LinkedNode* linked = malloc(sizeof(LinkedNode) * 9);

  linked[0] = (LinkedNode){1, NULL};
  linked[1] = (LinkedNode){2, NULL};
  linked[2] = (LinkedNode){3, NULL};
  linked[3] = (LinkedNode){4, NULL};
  linked[4] = (LinkedNode){5, NULL};
  linked[5] = (LinkedNode){6, NULL};
  linked[6] = (LinkedNode){7, NULL};
  linked[7] = (LinkedNode){8, NULL};
  linked[8] = (LinkedNode){9, NULL};
  linked[0].next = &linked[1];
  linked[1].next = &linked[2];
  linked[2].next = &linked[3];
  linked[3].next = &linked[4];
  linked[4].next = &linked[5];
  linked[5].next = &linked[6];
  linked[6].next = &linked[7];
  linked[7].next = &linked[8];

  //1 2 3 4 5 6 7 8 9
  duplicar_pares1(linked);
  return 0;
}
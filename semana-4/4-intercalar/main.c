#include <stdio.h>
#include <stdlib.h>
#include "intercalar.h"


// void imprimir1(LinkedNode *inicio)
// {

//   LinkedNode *actualNode = inicio;
//   while (actualNode != NULL)
//   {
//     if (actualNode->next == NULL)
//     {
//       printf("%d\n", actualNode->data);
//     }
//     else
//     {
//       printf("%d ", actualNode->data);
//     }
//     actualNode = actualNode->next;
//   }
// }

int main(int argc, char const *argv[])
{
  LinkedNode *linked = malloc(sizeof(LinkedNode) * 6);
  LinkedNode *linked1 = malloc(sizeof(LinkedNode) * 6);

  linked[0] = (LinkedNode){2, NULL};
  linked[1] = (LinkedNode){4, NULL};
  linked[2] = (LinkedNode){6, NULL};
  linked[3] = (LinkedNode){8, NULL};
  linked[4] = (LinkedNode){10, NULL};
  linked[5] = (LinkedNode){15, NULL};
  linked[0].next = &linked[1];
  linked[1].next = &linked[2];
  linked[2].next = &linked[3];
  linked[3].next = &linked[4];
  linked[4].next = &linked[5];

  linked1[0] = (LinkedNode){1, NULL};
  linked1[1] = (LinkedNode){3, NULL};
  linked1[2] = (LinkedNode){5, NULL};
  linked1[3] = (LinkedNode){7, NULL};
  linked1[4] = (LinkedNode){9, NULL};
  linked1[5] = (LinkedNode){11, NULL};
  linked1[0].next = &linked1[1];
  linked1[1].next = &linked1[2];
  linked1[2].next = &linked1[3];
  linked1[3].next = &linked1[4];
  linked1[4].next = &linked1[5];

  // 1 2 3 4 5 6 7 8 9
  imprimir1(intercalar_listas(linked, linked1));
  return 0;
}
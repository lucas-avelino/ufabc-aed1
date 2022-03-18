#include <stdio.h>
#include <stdlib.h>
#include "editar_dna.h"
// void imprimir1(LinkedNode *inicio)
// {

//   LinkedNode *actualNode = inicio;
//   while (actualNode != NULL)
//   {
//     if (actualNode->next == NULL)
//     {
//       printf("%c\n", actualNode->data);
//     }
//     else
//     {
//       printf("%c ", actualNode->data);
//     }
//     actualNode = actualNode->next;
//   }
// }


LinkedNode *createLinkedListFromArray(char const *array)
{
  LinkedNode *inicio = malloc(sizeof(LinkedNode));
  printf("malloc -> %p\n", inicio);
  LinkedNode *anterior = inicio;
  inicio->data = array[0];
  for (int i = 1; array[i] != '\0'; i++)
  {
    LinkedNode *newNode = malloc(sizeof(LinkedNode));
    printf("malloc -> %p\n", newNode);
    anterior->next = newNode;
    newNode->data = array[i];
    newNode->next = NULL;
    anterior = anterior->next;
  }

  return inicio;
}

int main(int argc, char const *argv[])
{
  // LinkedNode *linked = malloc(sizeof(LinkedNode) * 6);
  // LinkedNode *linked1 = malloc(sizeof(LinkedNode) * 2);

  // linked[0] = (LinkedNode){'A', NULL};
  // linked[1] = (LinkedNode){'A', NULL};
  // linked[2] = (LinkedNode){'B', NULL};
  // linked[3] = (LinkedNode){'C', NULL};
  // linked[4] = (LinkedNode){'A', NULL};
  // linked[5] = (LinkedNode){'B', NULL};
  // linked[0].next = &linked[1];
  // linked[1].next = &linked[2];
  // linked[2].next = &linked[3];
  // linked[3].next = &linked[4];
  // linked[4].next = &linked[5];

  // linked1[0] = (LinkedNode){'A', NULL};
  // linked1[1] = (LinkedNode){'B', NULL};
  // linked1[0].next = &linked1[1];

  LinkedNode *DNA = createLinkedListFromArray("GCGCCTACGATAAGGCGCGCCAACAGGCGCCG");
  LinkedNode *remove = createLinkedListFromArray("CGCGG");
  printf("DNA -> ");
  imprimir1(DNA);
  printf("remove -> ");
  imprimir1(remove);

  // 1 2 3 4 5 6 7 8 9
  LinkedNode *result = editar_dna(DNA, remove);
  printf("%ld\n", result);
  imprimir1(result);
  return 0;
}
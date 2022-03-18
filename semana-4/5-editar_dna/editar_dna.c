#include <stdlib.h>
#include "editar_dna.h"
// ACGT
// TGCA

void imprimir1(LinkedNode *inicio)
{

  LinkedNode *actualNode = inicio;
  while (actualNode != NULL)
  {
    if (actualNode->next == NULL)
    {
      printf("%c\n", actualNode->data);
    }
    else
    {
      printf("%c", actualNode->data);
    }
    actualNode = actualNode->next;
  }
}

char genesEqual(char a, char b)
{
  if (
      (a == 'A' && b == 'T') ||
      (a == 'C' && b == 'G') ||
      (a == 'G' && b == 'C') ||
      (a == 'T' && b == 'A'))
    return 1;

  return 0;
}

void clearLinkedNode(LinkedNode *delete)
{
  if (delete->next != NULL)
  {
    clearLinkedNode(delete->next);
  }
  delete->next = NULL;
  printf("free -> %p\n", delete);
  free(delete);
}

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao)
{
  LinkedNode *actual = dna_original;
  LinkedNode *prev = NULL;
  LinkedNode *result = dna_original;

  if (dna_original == NULL)
  {
    return NULL;
  }
  if (seq_edicao == NULL)
  {
    return result;
  }
  while (actual != NULL)
  {
    if (genesEqual(actual->data, seq_edicao->data) == 1)
    {
      LinkedNode *comparatorOriginalDNA = actual;
      LinkedNode *comparatorEditSeq = seq_edicao;
      while (genesEqual(comparatorOriginalDNA->data, comparatorEditSeq->data) == 1)
      {
        if (comparatorEditSeq->next == NULL)
        {
          LinkedNode *temp = comparatorOriginalDNA->next;
          comparatorOriginalDNA->next = NULL;
          clearLinkedNode(actual);
          if (prev != NULL)
          {
            prev->next = temp;
            actual = temp;
          }
          else
          {
            actual = temp;
            result = temp;
          }
          break;
        }
        comparatorOriginalDNA = comparatorOriginalDNA->next;
        comparatorEditSeq = comparatorEditSeq->next;
      }
      if (genesEqual(comparatorOriginalDNA->data, comparatorEditSeq->data) == 0)
      {
        if (actual == NULL)
        {
          break;
        }
        prev = actual;
        actual = actual->next;
      }
    }
    else
    {
      if (actual == NULL)
      {
        break;
      }
      prev = actual;
      actual = actual->next;
    }
  }
  return result;
}
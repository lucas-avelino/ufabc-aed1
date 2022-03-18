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
  if (dna_original == NULL)
    return NULL;
  if (seq_edicao == NULL)
    return dna_original;

  LinkedNode *result = dna_original;

  if (genesEqual(dna_original->data, seq_edicao->data) == 1)
  {
    LinkedNode *comparatorOriginalDNA = dna_original;
    LinkedNode *comparatorEditSeq = seq_edicao;
    char found = 0;
    while (comparatorEditSeq != NULL && comparatorOriginalDNA != NULL && genesEqual(comparatorOriginalDNA->data, comparatorEditSeq->data) == 1)
    {
      if (comparatorEditSeq->next == NULL)
      {
        found = 1;
        break;
      }
      comparatorOriginalDNA = comparatorOriginalDNA->next;
      comparatorEditSeq = comparatorEditSeq->next;
    }
    if (found == 1)
    {
      LinkedNode *temp = editar_dna(comparatorOriginalDNA->next, seq_edicao);
      comparatorOriginalDNA->next = NULL;
      clearLinkedNode(dna_original);
      return temp;
    }
    else if(dna_original->next != NULL)
    {
      dna_original->next = editar_dna(dna_original->next, seq_edicao);
    }
  }
  else if (dna_original->next != NULL)
  {
    dna_original->next = editar_dna(dna_original->next, seq_edicao);
  }
  return result;
}
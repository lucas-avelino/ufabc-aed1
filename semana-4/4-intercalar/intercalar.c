#include <stdlib.h>
#include "intercalar.h"

LinkedNode *intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2)
{
  LinkedNode *resultado = NULL;
  LinkedNode *ponteiroAuxiliar;
  LinkedNode *ponteiro1 = inicio1;
  LinkedNode *ponteiro2 = inicio2;
  if (inicio1 == NULL)
  {
    return inicio2;
  }
  if (inicio2 == NULL)
  {
    return inicio1;
  }

  if (ponteiro1->data < ponteiro2->data)
  {
    resultado = ponteiro1;
    ponteiro1 = ponteiro1->next;
  }
  else
  {
    resultado = ponteiro2;
    ponteiro2 = ponteiro2->next;
  }

  ponteiroAuxiliar = resultado;
  while (ponteiro1 != NULL && ponteiro2 != NULL)
  {
    if (ponteiro1->data < ponteiro2->data)
    {
      ponteiroAuxiliar->next = ponteiro1;
      ponteiroAuxiliar = ponteiro1;
      ponteiro1 = ponteiro1->next;
      continue;
    }
    ponteiroAuxiliar->next = ponteiro2;
    ponteiroAuxiliar = ponteiro2;
    ponteiro2 = ponteiro2->next;
  }

  if (ponteiro1 == NULL)
  {
    ponteiroAuxiliar->next = ponteiro2;
  }
  else
  {
    ponteiroAuxiliar->next = ponteiro1;
  }

  return resultado;
}

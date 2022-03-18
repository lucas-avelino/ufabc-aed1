#include <stdlib.h>
#include "inverter.h"

LinkedNode *inverter_lista(LinkedNode *inicio)
{
  if (inicio == NULL || inicio->next == NULL)
  {
    return inicio;
  }
  LinkedNode *finalLista = inverter_lista(inicio->next);
  inicio->next->next = inicio;
  inicio->next = NULL;
  return finalLista;
}
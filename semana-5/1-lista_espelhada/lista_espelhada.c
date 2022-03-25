#include <stdlib.h>
#include "lista.h"
#include "lista_espelhada.h"
#include "pilha.h"
#include "fila.h"

int verificar_lista(LinkedNode *lista)
{
  PilhaDinamica *pilha = criar_pilha();
  FilaDinamica *queue = criar_fila();
  LinkedNode *actual = lista;
  int count = 0;

  while (actual != NULL)
  {
    push(pilha, actual->data);
    enqueue(queue, actual->data);
    count++;
    actual = actual->next;
  }

  int isMirrored = 1;
  for (int i = 0; i < count / 2; i++)
  {
    int pilhaItem = 0, queueItem = 0;
    pop(pilha, &pilhaItem);
    dequeue(queue, &queueItem);
    if (pilhaItem != queueItem)
    {
      isMirrored = 0;
    }
  }

  liberar_pilha(pilha);
  liberar_fila(queue);
  return isMirrored;
}
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

PilhaDinamica *criar_pilha();
int push(PilhaDinamica *pilha, char item);
int pop(PilhaDinamica *pilha, char *item);
void liberar_pilha(PilhaDinamica *pilha);

int main()
{
  char expression[100];
  scanf("%s\n", expression);

  PilhaDinamica *pilha = criar_pilha();
  int isCorrect = 1;
  int pilhaCount = 0;
  for (int i = 0; expression[i] != '\0'; i++)
  {
    if (expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
      push(pilha, expression[i]);
      pilhaCount++;
    }

    if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
    {
      char lastOpenChar;
      pop(pilha, &lastOpenChar);
      pilhaCount--;
      if (!((expression[i] == ')' && lastOpenChar == '(') ||
            (expression[i] == '}' && lastOpenChar == '{') ||
            (expression[i] == ']' && lastOpenChar == '[')) ||
            pilhaCount < 0)
      {
        isCorrect = 0;
        break;
      }
    }
  }
  char pendingChar;
  pop(pilha, &pendingChar);

  if (
    pilhaCount > 0)
  {
    isCorrect = 0;
  }
  printf("%s\n", isCorrect == 1 ? "SIM" : "NAO");
  liberar_pilha(pilha);
  return 0;
}
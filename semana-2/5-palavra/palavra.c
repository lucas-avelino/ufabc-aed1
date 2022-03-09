#include "palavra.h"

void deslocate(char *text, int position, int increment)
{
  if (text[position] == '\0')
  {
    text[position + increment] = text[position];
    return;
  }
  char toDeslocateChar = text[position];
  deslocate(text, position + 1, increment);
  text[position + increment] = toDeslocateChar;
}

void substituir_palavra(char *texto, char *palavra1, char *palavra2)
{
  int matchPosition = 0;
  int palavra1Size = 0;
  int palavra2Size = 0;

  while (palavra1[palavra1Size] != '\0')
  {
    palavra1Size++;
  }
  while (palavra2[palavra2Size] != '\0')
  {
    palavra2Size++;
  }

  int sizeDiference = palavra2Size - palavra1Size;

  for (int index = 0; texto[index] != '\0'; index++)
  {
    if (palavra1[matchPosition] == '\0' && (texto[index] == '\0' || texto[index] == ' ' || texto[index] == '.' || texto[index] == ','))
    { 
      int initialPosition = index - matchPosition;
      if (sizeDiference != 0)
        deslocate(texto, index - 1, sizeDiference);
      for (int replacePos = initialPosition; palavra2[replacePos - initialPosition] != '\0'; replacePos++)
      {
        texto[replacePos] = palavra2[replacePos - initialPosition];
      }
      index += sizeDiference;
      continue;
    }
    if (texto[index] == palavra1[matchPosition] || texto[index] - 32 == palavra1[matchPosition])
    {
      matchPosition++;
    }
    else
    {
      matchPosition = 0;
    }
  }
}

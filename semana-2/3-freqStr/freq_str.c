// #include "freq_str.h"
#include <stdio.h>

void main()
{
  char *search = "teste";
  char *text = "teste teste";
  int qtd = 0;

  frequencia_string(search, text, &qtd);

  printf("%d\n", qtd);
}

void frequencia_string(const char *str, const char *texto, int *qtd)
{
  int matchCount = 0;

  for (int i = 0; texto[i] != '\0'; i++)
  {

    if (texto[i] == str[0] || texto[i] - 32 == str[0])
    {
      for (int matchIndex = 0; str[matchIndex] != '\0'; matchIndex++)
      {
        if (!(texto[i + matchIndex] == str[matchIndex] || texto[i + matchIndex] - 32 == str[matchIndex]))
        {
          break;
        }
        if (str[matchIndex + 1] == '\0')
        {
          matchCount++;
        }
      }
    }
  }
  *qtd = matchCount;
}
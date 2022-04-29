// #include "ordenar.h"
#include "funcao_comparar.h"

int compareStrings(char *string1, char *string2)
{
  int i;
  for (i = 0; string1[i] != '\0' && string2[i] != '\0'; i++)
  {
    if (string1[i] > string2[i])
    {
      return 1;
    }
    if (string1[i] < string2[i])
    {
      return -1;
    }
  }
  if (string2[i] == '\0' && string1[i] !=  '\0')
  {
    return 1;
  }
  else if(string1[i] == '\0' && string2[i] !=  '\0')
  {
    return -1;
  }

  return 0;
}

int comparar(ItemVetor item1, ItemVetor item2)
{
  int modelCompare = compareStrings(item1.modelo, item2.modelo);
  int planetCompare = compareStrings(item1.planeta, item2.planeta);
  int autonomyCompare = item1.autonomia > item2.autonomia ? 1 : (item1.autonomia < item2.autonomia ? -1 : 0);

  if(autonomyCompare != 0){
    return autonomyCompare;
  }

  if(planetCompare != 0){
    return planetCompare;
  }

  return modelCompare;

}
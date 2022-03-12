#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main(int argc, char const *argv[])
{
  DiscoVoador discos[8] = {
      (DiscoVoador){"DiscoF", "Jupiter", 90},
      (DiscoVoador){"DiscoD", "Marte", 40},
      (DiscoVoador){"DiscoE", "Marte", 40},
      (DiscoVoador){"DiscoC", "Marte", 25},
      (DiscoVoador){"DiscoH", "Saturno", 150},
      (DiscoVoador){"DiscoG", "Saturno", 90},
      (DiscoVoador){"DiscoA", "Terra", 500},
      (DiscoVoador){"DiscoB", "Terra", 20}};

  printf("%d\n", verificar_ordenacao(&discos, 8));

  return 0;
}

cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./editar_dna.c -o ./editar_dna.o
gcc -o ./main.o ./main.c ./editar_dna.o
# echo "-------Running-------"
# ./main.o
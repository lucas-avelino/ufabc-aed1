cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./abb_menor_chave.c -o ./abb_menor_chave.o
gcc -o ./main.o ./main.c ./abb_menor_chave.o
echo "-------Running-------"
# ./main.o
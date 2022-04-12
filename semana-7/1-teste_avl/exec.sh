cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./teste_avl.c -o ./teste_avl.o
gcc -o ./main.o ./main.c ./teste_avl.o
echo "-------Running-------"
# ./main.o
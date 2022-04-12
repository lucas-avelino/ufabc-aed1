cd "$(dirname "${BASH_SOURCE[0]}")"


# gcc -Wall -g -c ./teste_avl.c -o ./teste_avl.o
gcc -g -o ./main.o ./main.c
echo "-------Running-------"
# ./main.o
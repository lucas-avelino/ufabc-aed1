cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./ordenar.c -o ./ordenar.o
gcc -o ./main.o ./main.c ./ordenar.o
echo "-------Running-------"
# ./main.o
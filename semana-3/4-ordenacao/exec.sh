cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./ordenacao.c -o ./ordenacao.o
gcc -o ./main.o ./main.c ./ordenacao.o
echo "-------Running-------"
./main.o
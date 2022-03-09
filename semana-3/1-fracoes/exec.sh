cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./fracoes.c -o ./fracoes.o
gcc -o ./main.o ./main.c ./fracoes.o
echo "-------Running-------"
./main.o
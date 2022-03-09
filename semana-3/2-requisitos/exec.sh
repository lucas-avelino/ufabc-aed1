cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./requisitos.c -o ./requisitos.o
gcc -o ./main.o ./main.c ./requisitos.o
echo "-------Running-------"
./main.o
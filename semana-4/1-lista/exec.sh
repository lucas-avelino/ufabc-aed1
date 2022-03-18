cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./lista.c -o ./lista.o
gcc -o ./main.o ./main.c ./lista.o
echo "-------Running-------"
./main.o
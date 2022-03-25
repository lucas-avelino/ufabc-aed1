cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./lista_espelhada.c -o ./lista_espelhada.o
gcc -o ./main.o ./main.c ./lista_espelhada.o
echo "-------Running-------"
./main.o
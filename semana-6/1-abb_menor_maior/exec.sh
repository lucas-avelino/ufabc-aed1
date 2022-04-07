cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./abb_menor_maior.c -o ./abb_menor_maior.o
gcc -o ./main.o ./main.c ./abb_menor_maior.o
echo "-------Running-------"
./main.o
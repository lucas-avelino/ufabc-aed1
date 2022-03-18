cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./duplicar.c -o ./duplicar.o
gcc -o ./main.o ./main.c ./duplicar.o
echo "-------Running-------"
./main.o
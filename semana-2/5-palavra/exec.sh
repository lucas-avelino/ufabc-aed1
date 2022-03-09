cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./palavra.c -o ./palavra.o
gcc -o ./main.o ./main.c ./palavra.o
echo "-------Running-------"
./main.o
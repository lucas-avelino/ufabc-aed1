cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./insertionsort.c -o ./insertionsort.o
gcc -g -o ./main.o ./main.c ./insertionsort.o
echo "-------Running-------"
# ./main.o
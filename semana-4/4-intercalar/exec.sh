cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./intercalar.c -o ./intercalar.o
gcc -o ./main.o ./main.c ./intercalar.o
# echo "-------Running-------"
# ./main.o
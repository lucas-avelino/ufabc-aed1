cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./abb_sucessor_antecessor.c -o ./abb_sucessor_antecessor.o
gcc -o ./main.o ./main.c ./abb_sucessor_antecessor.o
echo "-------Running-------"
./main.o
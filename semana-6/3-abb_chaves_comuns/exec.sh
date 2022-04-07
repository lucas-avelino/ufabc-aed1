cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./abb_chaves_comuns.c -o ./abb_chaves_comuns.o
gcc -o ./main.o ./main.c ./abb_chaves_comuns.o
echo "-------Running-------"
./main.o
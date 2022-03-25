cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./verifica_expressao.c -o ./verifica_expressao.o
gcc -o ./main.o ./main.c ./verifica_expressao.o
echo "-------Running-------"
./main.o
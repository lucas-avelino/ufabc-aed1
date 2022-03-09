cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./disciplinas.c -o ./disciplinas.o
gcc -o ./main.o ./main.c ./disciplinas.o
echo "-------Running-------"
./main.o
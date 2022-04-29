cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./funcao_comparar.c -o ./funcao_comparar.o
gcc -o ./main.o ./main.c ./funcao_comparar.o
echo "-------Running-------"
# ./main.o
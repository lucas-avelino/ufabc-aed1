cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./abb_string.c -o ./abb_string.o
gcc -o ./main.o ./main.c ./abb_string.o
echo "-------Running-------"
# ./main.o
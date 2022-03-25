cd "$(dirname "${BASH_SOURCE[0]}")"

gcc -o ./main.o ./main.c
echo "-------Running-------"
./main.o < input.txt
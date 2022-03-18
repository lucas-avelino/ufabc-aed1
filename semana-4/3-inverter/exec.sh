cd "$(dirname "${BASH_SOURCE[0]}")"


gcc -Wall -g -c ./inverter.c -o ./inverter.o
gcc -o ./main.o ./main.c ./inverter.o
echo "-------Running-------"
./main.o
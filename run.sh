rm -rf main *.o
gcc -c *.c
gcc -o main *.o
./main
rm -rf main *.o
.PHONEY: all clean

all:
	gcc -Ilibso -c *.c
	gcc *.o -Llibso my_print.a -o main

clean:
	rm *.o main

.PHONY: all clean
 
 all:
	gcc -o static.o -shared -fPIC -c static.c
	ar -r libstatic.a static.o
	gcc -o dynamic.o -c dynamic.c
	gcc -o libdynamic.so -shared -fPIC dynamic.o -Wl,-all_load libstatic.a # -L. -lstatic
	gcc main.c -o main -L. -ldynamic

clean:
	rm *.o lib*
xminmax: ../xminmax.c binsearch
	gcc -O3 -fPIC -shared -DKXVER=3 ../xminmax.c binsearch.o -o xminmax.so
binsearch: ../binsearch.c ../binsearch.h 
	gcc -O3 -fPIC -c -DKXVER=3 ../binsearch.c -o binsearch.o


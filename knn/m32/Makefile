xminmax: ../xminmax.c binsearch
	gcc -O3 -m32 -bundle -undefined dynamic_lookup -DKXVER=3 ../xminmax.c binsearch.o -o xminmax.so
binsearch: ../binsearch.c 
	gcc -O3 -m32 -fPIC -c -DKXVER=3 ../binsearch.c -o binsearch.o


all: ../extend.c 
	gcc -m32 -DKXVER=3 -bundle -undefined dynamic_lookup ../extend.c -o extend.so
	gcc -m32 -DKXVER=3 ../client.c c.o -o ../client

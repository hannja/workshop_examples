all:	../extend.c ../client.c
	gcc -m32 -DKXVER=3 -fPIC -shared ../extend.c -o extend.so
	gcc -m32 -DKXVER=3 ../client.c c.o -o ../client -lpthread

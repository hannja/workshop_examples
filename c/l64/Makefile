all:	../extend.c ../client.c
	gcc -DKXVER=3 -fPIC -shared ../extend.c -o extend.so
	gcc -DKXVER=3 ../client.c c.o -o ../client -lpthread

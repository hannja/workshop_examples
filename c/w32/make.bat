cl /DKXVER=3 /LD extend.c extend.def q.lib
cl /DKXVER=3 client.c c.lib ws2_32.lib 

#include "k.h"
#include <stdio.h>
int main(int argc,char* argv[]){

	printf("connecting to kdb+ on localhost 5001\n");
	int c=khp("localhost",5001);
	if(-1==c){
		printf("Could not connect\n");
		return 1;
	}
	printf("defining testtable:([]a:til 10;b:10?`A`B`C) on server\n\n");
	k(c,"testtable:([]a:til 100;b:100?`A`B`C)",(K)0);
	printf("total greater than with a>2 for each b value\n\n");
	// pass parameters to kdb+, you can use up to 8
	K res=k(c,"{0!select number:count i by b from testtable where a>x}",ki(2),(K)0);
	K colnames=kK(res->k)[0];
	K colvals=kK(res->k)[1];
	J i,j,nrows;
	// print column headers
	for(i=0;i<colnames->n;i++)
		printf("%s\t",kS(colnames)[i]);
	printf("\n\n");
	// print values in each row
	nrows=kK(colvals)[0]->n;
	for(j=0;j<nrows;j++){
		// each row has a symbol and an integer
		printf("%s\t%lld\n",kS(kK(colvals)[0])[j],kJ(kK(colvals)[1])[j]);
	}

	return 0;
 	}
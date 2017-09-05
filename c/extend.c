#include "k.h"
K1(add10){
	// type check, raise error if not provided longs
	if(KJ!=x->t)
		R krr("type error, must provide list of longs");
	// access x as a long vector, add 10 to each element and return the result
	K res=ktn(KJ,x->n);
	J i;
	for(i=0;i<x->n;i++)
		kJ(res)[i]=kJ(x)[i]+10;
	R res;
	}
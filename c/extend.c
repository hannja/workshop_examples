#include "k.h"
// single argument function
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
// note this is just wsum in q
K dotproduct(K x,K y){
	// type check, raise error if not provided longs
	if(KJ!=x->t)
		R krr("type error, x");
	if(KJ!=y->t)
		R krr("type error, y");
	if(x->n!=y->n)
		R krr("vectors must be same length");
	J res=0;
	J i;
	for(i=0;i<x->n;i++)
		res+=kJ(x)[i]*kJ(y)[i];
	R kj(res);
	}
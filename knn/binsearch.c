#include "binsearch.h"
#define mk_binsearch(TYPE)\
	QI binsearch_##TYPE(TYPE* x,TYPE y,QI lw,QI mid,QI hw){\
		while(hw>lw){\
			/*right*/\
			if(x[mid]<y)\
				lw=mid+1;\
			/* left*/\
			else if(x[mid]>y)\
				hw=mid-1;\
			/* equal */\
			else\
				break;\
			mid=(hw+lw)/2;\
		};\
		if(x[mid]>y)\
			mid--;\
		while((x[mid+1]==x[mid])&&mid<hw){mid++;};\
		R mid;\
	}
mk_binsearch(H)
mk_binsearch(I)
mk_binsearch(J)
mk_binsearch(F)
mk_binsearch(E)
/*
 * example for longs 
 *
QI binsearch(J* x,J y,QI mid,QI lw,QI hw){
	while(hw>lw){
		if(x[mid]<y){ // right
     lw=mid+1; //lw==mid?mid+1:mid;
		}else if(x[mid]>y){ // left
		 hw=mid-1;	
		}else{ //equal find last index 
			break;
		}
    mid=(hw+lw)/2;
 }
 if(x[mid]>y)
  mid--;
 
 while((x[mid+1]==x[mid])&&mid<hw){mid++;}
 R mid;
 }
*/

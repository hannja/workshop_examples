#include "q.h"
#define mk_decl_binsearch(TYPE)\
	QI binsearch_##TYPE(TYPE* x,TYPE y,QI lw,QI mid,QI hw);
mk_decl_binsearch(H)
mk_decl_binsearch(I)
mk_decl_binsearch(J)
mk_decl_binsearch(F)
mk_decl_binsearch(E)

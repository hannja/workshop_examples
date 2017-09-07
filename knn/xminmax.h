#include "q.h"
#define mk_decl_xminmax(MINMAX,TYPE)\
	K x_##MINMAX##_i_##TYPE(QI x,K y);
#define mk_decl_ximinmax(MINMAX,TYPE)\
	K xi_##MINMAX##_i_##TYPE(QI x,K y);
#define mk_decl_maint(MINMAX,TYPE)\
	void maint_##MINMAX##s_i_##TYPE(TYPE *x,QI length,TYPE y);
#define mk_decl_imaint(MINMAX,TYPE)\
	void maint_i##MINMAX##s_i_##TYPE(QI *res,TYPE *x,QI length,TYPE y,QI yi);
#define decl_xminmax(TYPE)\
	mk_decl_maint(min,TYPE);mk_decl_maint(max,TYPE);mk_decl_imaint(min,TYPE);mk_decl_imaint(max,TYPE);\
	mk_decl_xminmax(min,TYPE);mk_decl_xminmax(max,TYPE);mk_decl_ximinmax(min,TYPE);mk_decl_ximinmax(max,TYPE);
decl_xminmax(H)
decl_xminmax(I)
decl_xminmax(J)
decl_xminmax(F)
decl_xminmax(E)

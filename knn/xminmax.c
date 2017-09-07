#include "q.h"
#include <string.h>
#include <stdio.h>
#include "binsearch.h"
#include "xminmax.h"

#define mk_xminmax(MINMAX,TYPE,TYPEINF,NEGATION) \
	K x##MINMAX##_i_##TYPE(QI x,K y){\
		K res=ktn(K##TYPE,x);\
		QI i;\
		for(i=0;i<x;i++)\
			k##TYPE(res)[i]=NEGATION TYPEINF;\
		for(i=0;i<y->n;i++)\
			maint_##MINMAX##s_i_##TYPE(k##TYPE(res),res->n,k##TYPE(y)[i]);\
		R res;\
	}
#define mk_ximinmax(MINMAX,TYPE,TYPEINF,NEGATION)\
	K xi##MINMAX##_i_##TYPE(QI x,K y){\
		K res=ktn(QILIST_T,x);\
		K tmp=ktn(K##TYPE,x);\
		QI i;\
		for(i=0;i<x;i++){\
			qI(res)[i]=-1;\
			k##TYPE(tmp)[i]=NEGATION TYPEINF;\
		}\
		for(i=0;i<y->n;i++)\
			maint_i##MINMAX##s_i_##TYPE(qI(res),k##TYPE(tmp),res->n,k##TYPE(y)[i],i);\
		R res;\
	}

/* insert into sorted list of current minimums */
#define mk_maint_mins(TYPE)\
	void maint_mins_i_##TYPE(TYPE* x,QI length,TYPE y){\
		QI i=0;\
		/*TODO, find a good way to approximate a good limit for this problem */\
		if(length>8)\
			i=1+binsearch_##TYPE(x,y,0,0,length-1);\
		else{\
			for(;i<length;i++)\
				if(y<x[i])break;\
		}\
		if(i<length){\
			if(i<length-1)\
				memmove(&x[i+1],&x[i],sizeof(TYPE)*(length-(i+1)));\
		x[i]=y;\
		}\
		}
/* same but maintaining indices of minimum values */
#define mk_imaint_mins(TYPE)\
	void maint_imins_i_##TYPE(QI* res,TYPE* x,QI length,TYPE y,QI yi){\
		QI i=0;\
		/*TODO, find a good way to approximate a good limit for this problem */\
		if(length>8)\
			i=1+binsearch_##TYPE(x,y,0,0,length-1);\
		else{\
			for(;i<length;i++)\
				if(y<x[i])break;\
		}\
		if(i<length){\
			if(i<length-1){\
				memmove(&x[i+1],&x[i],sizeof(TYPE)*(length-(i+1)));\
				memmove(&res[i+1],&res[i],sizeof(QI)*(length-(i+1)));\
			}\
		x[i]=y;\
		res[i]=yi;\
		}\
		}
/* insert into sorted list of current maximums */
#define mk_maint_maxs(TYPE)\
	void maint_maxs_i_##TYPE(TYPE* x,QI length,TYPE y){\
		QI i=length-1;\
		/*TODO, find a good way to approximate a good limit for this problem */\
		if(length>8)\
			i=binsearch_##TYPE(x,y,0,(length-1)/2,length-1);\
		else{\
			for(;i>-1;i--)\
				if(y>=x[i])break;\
		}\
		if(i>-1){\
			if(i>0)\
				memmove(x,&x[1],sizeof(TYPE)*i);\
		x[i]=y;\
		}\
		}

#define def_minmax(TYPE,INFVAL)\
	mk_xminmax(min,TYPE,INFVAL,);mk_ximinmax(min,TYPE,INFVAL,);mk_xminmax(max,TYPE,INFVAL,-);mk_maint_mins(TYPE);mk_maint_maxs(TYPE);mk_imaint_mins(TYPE);
def_minmax(J,wj)
def_minmax(F,wf)
def_minmax(E,wf)
def_minmax(H,wh)
def_minmax(I,wh)

// functions exposed to q
K2(xmin){
  K res;
  if(QIATOM_T!=xt)R krr("x argument must be number of results as default integer for kdb+ version");
  SW(y->t){
		CS(KH,R xmin_i_H(qint(x),y))
		CS(KI,R xmin_i_I(qint(x),y))
		CS(KJ,R xmin_i_J(qint(x),y))
		CS(KE,R xmin_i_E(qint(x),y))
		CS(KF,R xmin_i_F(qint(x),y))
		CS(KP,res=xmin_i_J(qint(x),y);res->t=KP;R res)
		CS(KM,res=xmin_i_I(qint(x),y);res->t=KM;R res)
		CS(KD,res=xmin_i_I(qint(x),y);res->t=KD;R res)
		CS(KN,res=xmin_i_J(qint(x),y);res->t=KN;R res)
		CS(KU,res=xmin_i_I(qint(x),y);res->t=KU;R res)
		CS(KV,res=xmin_i_I(qint(x),y);res->t=KV;R res)
		CS(KT,res=xmin_i_I(qint(x),y);res->t=KT;R res)
		CD:R krr("unsupported type");}
	}
K2(ximin){
  K res;
  if(QIATOM_T!=xt)R krr("x argument must be number of results as default integer for kdb+ version");
  SW(y->t){
		CS(KH,R ximin_i_H(qint(x),y))
		CS(KI,R ximin_i_I(qint(x),y))
		CS(KJ,R ximin_i_J(qint(x),y))
		CS(KE,R ximin_i_E(qint(x),y))
		CS(KF,R ximin_i_F(qint(x),y))
		CS(KP,res=ximin_i_J(qint(x),y);res->t=KP;R res)
		CS(KM,res=ximin_i_I(qint(x),y);res->t=KM;R res)
		CS(KD,res=ximin_i_I(qint(x),y);res->t=KD;R res)
		CS(KN,res=ximin_i_J(qint(x),y);res->t=KN;R res)
		CS(KU,res=ximin_i_I(qint(x),y);res->t=KU;R res)
		CS(KV,res=ximin_i_I(qint(x),y);res->t=KV;R res)
		CS(KT,res=ximin_i_I(qint(x),y);res->t=KT;R res)
		CD:R krr("unsupported type");}
	}
K2(xmax){
  K res;
  if(QIATOM_T!=xt)R krr("x argument must be number of results as default integer for kdb+ version");
  SW(y->t){
		CS(KH,R xmax_i_H(qint(x),y))
		CS(KI,R xmax_i_I(qint(x),y))
		CS(KJ,R xmax_i_J(qint(x),y))
		CS(KE,R xmax_i_E(qint(x),y))
		CS(KF,R xmax_i_F(qint(x),y))
		CS(KP,res=xmax_i_J(qint(x),y);res->t=KP;R res)
		CS(KM,res=xmax_i_I(qint(x),y);res->t=KM;R res)
		CS(KD,res=xmax_i_I(qint(x),y);res->t=KD;R res)
		CS(KN,res=xmax_i_J(qint(x),y);res->t=KN;R res)
		CS(KU,res=xmax_i_I(qint(x),y);res->t=KU;R res)
		CS(KV,res=xmax_i_I(qint(x),y);res->t=KV;R res)
		CS(KT,res=xmax_i_I(qint(x),y);res->t=KT;R res)
		CD:R krr("unsupported type");}
	}


#ifndef KX
#include "k.h"
#endif
/* index types different between 2.x and 3.x so passed indices
 * to functions may be of different types
 * define some of these differences away */
#if KXVER==2
#define QIATOM_T -KI    /* q atomic type id for index */
#define QILIST_T KI     /* q list type id for index */
#define qi(x) (ki(x))   /* make q integer of the correct type */
#define qI(x) (kI(x))   /* vector accessor for lists of inds  */
#define qind(x) (x->i)  /* atomic accessor */
#define qint(x) (x->i)  /* atomic accessor */
typedef I QI;           /* single type def for all ints to be used as q indices */
#elif KXVER==3
#define QIATOM_T -KJ
#define QILIST_T KJ
#define qi(x) (kj(x))
#define qI(x) (kJ(x))
#define qind(x) (x->j)
#define qint(x) (x->j)
typedef J QI;
#else
#error "Set KXVER=3 for kdb+3.0 or standalone c-api after 2011-04-20. Otherwise set KXVER=2"

#endif

#define QERR_T -128





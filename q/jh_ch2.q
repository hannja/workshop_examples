Chapter 2 extra material

__2.5__



/ Data types
type gives the type of any object
type<0 is 'atomic' singleton
type>0 is a list 
table/dictionary/function types start at 98


/ Character based data
/ As we've seen
q)"a" 		/ single character
q)"abc" 	/ character list
q)`aaa		/single symbol
q)`aaa`bbb	/ list of symbols

/ numeric data
q)01b 		/boolean
q)0x010a 	/bytes
q)0 1 2h	/short
q)0 1 2i	/4 byte int (int)  in kdb+ < 3.0 we only need 0 1 2
q)0 1 2		/8 byte int (long) in kdb+ < 3.0 we need 0 1 2j
q)0 1 2e	/single precision floating point (real)
q)0 1 2.0 	/ or 0 1 2f double precision floating point

/ Temporal types
q)2001.01.01 			/date 
q)2001.01m			/month 
q)00:00:00			/seconds
q)00:00				/minutes
q)2001.01.01D00:00:00.000	/timestamp (nanosecond precision)
q)2D00:00:00.000		/timespan  (nanosecond precision)
q)12:00:00.123			/time (millisecond precision, occasionally still used)
q)2001.01.01T12:00:00.000	/datetime (DEPRECATED)

/ other
q)rand 0Ng			/ 16 byte GUID




for a full list including sizes and mappings to other languages see
https://code.kx.com/q/ref/datatypes/

Indexing a vector out of range (e.g. with list@-1 or list 0N, gives a null for that type)

__2.6__

/Functions
Functions are first class citizens

we can define functions with up to 8 parameters
every function takes at least one parameter even it it is not referenced

we can create single line functions in the console, multi line functions need to be defined in scripts.

Functions can be anonymous 

Functions can refer to themselves (self referential)

The return from a function is the result of the last expression in the function
we can return early from a function by prefixing an expression with :

Globals can be defined in functions

Projections (fix one or more parameters) we can use 'first get' to retrieve the original function



Indexing at depth example.

q)x:(1 2 3;4 5 6)
q)x[;1]
q)x[0;1 2]


Adverbs
There is a full reference on adverbs and their uses here
http://code.kx.com/q/ref/elements/#adverbs













	


/`
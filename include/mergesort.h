#ifndef MERGESORT_H
#  define MERGESORT_H
#  ifndef STDLIB_H
#    include "stdlib.h"
#  endif

typedef unsigned char (*mergesort_callback)(int, int) ;

int *my_mergesort(int*, size_t, mergesort_callback);
#endif 

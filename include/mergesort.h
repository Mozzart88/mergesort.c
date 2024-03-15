#ifndef MERGESORT_H
#  define MERGESORT_H
#  ifndef STDLIB_H
#    include "stdlib.h"
#  endif
#  ifndef my_asc
#    define my_asc (i, j) (i < j)
#  endif
#  ifndef my_dsc
#    define my_dsc (i, j) (i >= j)
#  endif

typedef unsigned char (*mergesort_callback)(int, int) ;

int *my_mergesort(int*, size_t, mergesort_callback);
#endif 

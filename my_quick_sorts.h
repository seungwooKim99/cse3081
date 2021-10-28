//
// Created by Seungwoo Kim on 2021/10/26.
//

#ifndef HW2_MY_QUICK_SORTS_H
#define HW2_MY_QUICK_SORTS_H

#include <stdio.h>
#include <stdlib.h>

typedef int _Cmpfun(const void *, const void *);
void qsort_orig(void *, size_t, size_t, _Cmpfun *);
void qsort_median_insert(void *, size_t, size_t, _Cmpfun *);
void qsort_median_insert_iter(void *, size_t, size_t, _Cmpfun *);

#endif //HW2_MY_QUICK_SORTS_H

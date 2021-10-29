//
// Created by Seungwoo Kim on 2021/10/26.
//

#include "my_quick_sorts.h"
#define MAX_BUF	256

void exch(char* a, char* b, size_t size) {
    //SWAP a, b
    char buffer[MAX_BUF];
    char* q1 = a;
    char* q2 = b;
    size_t	m, ms;
    for(ms=size; 0<ms; ms-=m, q1+=m, q2+=m) {
        m = (ms < sizeof(buffer)) ? ms : sizeof(buffer);
        memcpy(buffer, q1, size);
        memcpy(q1, q2, size);
        memcpy(q2, buffer, size);
    }
}

void qsort_orig(void * base, size_t n, size_t size, _Cmpfun * cmp) {
    //Divide
    size_t right_size = 0;
    size_t left = 0;
    size_t right = n-1;
    char* q_left = (char*)base;
    char* q_right = q_left + size*right;
    char* q_pivot = q_right;
    if (left < right) {
        char *qi;
        for (qi = q_right; q_left < qi; qi -= size) {
            if ((*cmp)(qi, q_left) > 0) {
                //SWAP qi, q_pivot
                /*
                char buffer[MAX_BUF];
                char* q1 = qi;
                char* q2 = q_pivot;
                size_t	m, ms;
                for(ms=size; 0<ms; ms-=m, q1+=m, q2+=m) {
                    m = (ms < sizeof(buffer)) ? ms : sizeof(buffer);
                    memcpy(buffer, q1, size);
                    memcpy(q1, q2, size);
                    memcpy(q2, buffer, size);
                }
                 */
                exch(qi, q_pivot, size);
                q_pivot -= size;
                right_size++;
            }
        }
        //SWAP q_left, q_pivot
        char buffer[MAX_BUF];
        char* q1 = q_left;
        char* q2 = q_pivot;
        size_t	m, ms;
        for(ms=size; 0<ms; ms-=m, q1+=m, q2+=m) {
            m = (ms < sizeof(buffer)) ? ms : sizeof(buffer);
            memcpy(buffer, q1, size);
            memcpy(q1, q2, size);
            memcpy(q2, buffer, size);
        }

        //Conquer
        if (n-right_size-1 > 0){
            qsort_orig(base, n-right_size-1, size, cmp);
        }
        if (right_size > 0){
            qsort_orig(q_pivot + size, right_size, size, cmp);
        }
    }
}
void qsort_median_insert(void * base, size_t n, size_t size, _Cmpfun * cmp) {
    //

    //
}
void qsort_median_insert_iter(void * base, size_t n, size_t size, _Cmpfun * cmp) {

    //
}


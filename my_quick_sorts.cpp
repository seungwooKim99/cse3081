//
// Created by Seungwoo Kim on 2021/10/26.
//

#include "my_quick_sorts.h"
#define MAX_BUF	256

void qsort_orig(void * base, size_t n, size_t size, _Cmpfun * cmp) {
    //Divide
    size_t right_size = 0;
    size_t left = 0;
    size_t right = (n==0) ? 0 : n-1;
    char* q_left = (char*)base;
    char* q_right = q_left + size*right;
    char* q_pivot = q_right;
    if (left < right) {
        char *qi;
        for (qi = q_right; q_left < qi; qi -= size) {
            if ((*cmp)(qi, q_left) > 0) {
                //SWAP qi, q_pivot
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
                q_pivot -= size;
                right_size++;
            }
        }
        //SWAP(q_left, q_pivot)
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
        qsort_orig(base, n-right_size-1, size, cmp);
        qsort_orig(q_pivot + size, right_size, size, cmp);
    }
}
void qsort_median_insert(void * base, size_t n, size_t size, _Cmpfun * cmp) {
    //
    while(1<n)
    {
        size_t	i = 0;
        size_t	j = n-1;
        char*	qi = (char*)base;
        char*	qj = qi + size*j;
        char*	qp = qj;

        while(i<j)
        {
            while(i<j && (*cmp)(qi, qp) <= 0)
                ++i, qi += size;
            while(i<j && (*cmp)(qp, qj) <= 0)
                --j, qj -= size;

            if(i<j) {
                char	buf[MAX_BUF];
                char*	q1 = qi;
                char*	q2 = qj;
                size_t	m, ms;

                for(ms=size; 0<ms; ms-=m, q1+=m, q2+=m) {
                    m = (ms < sizeof(buf)) ? ms : sizeof(buf);
                    memcpy(buf, q1, m);
                    memcpy(q1, q2, m);
                    memcpy(q2, buf, m);
                }
                ++i, qi+=size;
            }
        }
        if(qi != qp) {
            char	buf[MAX_BUF];
            char*	q1 = qi;
            char*	q2 = qp;
            size_t	m, ms;

            for(ms=size; 0<ms; ms-=m, q1+=m, q2+=m) {
                m = (ms<sizeof(buf)) ? ms : sizeof(buf);
                memcpy(buf, q1, m);
                memcpy(q1, q2, m);
                memcpy(q2, buf, m);
            }
        }
        j = n-i-1, qi+=size;
        if(j<i) {
            if(1<j)
                qsort(qi, j, size, cmp);
            n = i;
        }
        else {
            if(1<i)
                qsort(base, i, size, cmp);
            base = qi;
            n =j;
        }
    }
    //
}
void qsort_median_insert_iter(void * base, size_t n, size_t size, _Cmpfun * cmp) {

    //
}


//
// Created by Seungwoo Kim on 2021/10/26.
//

#include "my_quick_sorts.h"
#define MAX_BUF	256
#define M 10

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

void compexch(char* a, char* b, size_t size, _Cmpfun * cmp) {
    //SWAP a, b if a < b
    if ((*cmp)(a ,b) > 0) {
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
}

void insertion_sort(void *base, size_t n, size_t size, _Cmpfun *cmp) {
    int i, j;
    char *qi = (char *)base;
    void *tmpBuffer = malloc(size);
    for(i=1;i<(int)n;i++){
        memcpy(tmpBuffer, qi + size*i, size);
        j = i;
        while((j>0) && ((*cmp)(tmpBuffer, qi + size*(j-1)) < 0)){
            memcpy(qi + size*j, qi + size*(j-1), size);
            j--;
        }
        memcpy(qi + size*j, tmpBuffer, size);
    }
    free(tmpBuffer);
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
                exch(qi, q_pivot, size);
                q_pivot -= size;
                right_size++;
            }
        }
        //SWAP q_left, q_pivot
        exch(q_left, q_pivot, size);

        //Conquer
        if (n-right_size-1 > 0){
            qsort_orig(base, n-right_size-1, size, cmp);
        }
        if (right_size > 0){
            qsort_orig(q_pivot + size, right_size, size, cmp);
        }
    }
}

void qsort_with_median(void *base, size_t n, size_t size, _Cmpfun *cmp){
    if ( n < M ) return;
    //Divide
    size_t right_size = 0;
    size_t left = 0;
    size_t right = n-1;
    char* q_left = (char*)base;
    char* q_right = q_left + size*right;
    char* q_mid = q_left + size*(right/2);

    exch(q_left+size, q_mid, size);
    compexch(q_left, q_left + size, size, cmp);
    compexch(q_left, q_right, size, cmp);
    compexch(q_left+size, q_right, size, cmp);

    //partition
    char* q_pivot = q_right - size;
    char *qi;
    for (qi = q_right - size; q_left + size < qi; qi -= size) {
        if ((*cmp)(qi, q_left + size) > 0) {
            exch(qi, q_pivot, size);
            q_pivot -= size;
            right_size++;
        }
    }
    //SWAP q_left, q_pivot
    exch(q_left + size, q_pivot, size);

    //Conquer
    if (n-right_size-1 > 0){
        qsort_with_median(base, n-right_size-1, size, cmp);
    }
    if (right_size > 0){
        qsort_with_median(q_pivot + size, right_size, size, cmp);
    }
}

void qsort_median_insert(void * base, size_t n, size_t size, _Cmpfun * cmp) {
    qsort_with_median(base, n, size, cmp);
    insertion_sort(base, n, size, cmp);
}
void qsort_median_insert_iter(void * base, size_t n, size_t size, _Cmpfun * cmp) {
    //Divide
    size_t right_size = 1;
    size_t left = 0;
    size_t right = n-1;
    char* q_left = (char*)base;
    char* q_right = q_left + size*right;
    char* q_mid = q_left + size*(right/2);

    exch(q_left+size, q_mid, size);
    compexch(q_left, q_left + size, size, cmp);
    compexch(q_left, q_right, size, cmp);
    compexch(q_left+size, q_right, size, cmp);

    //partition
    char* q_pivot = q_right - size;
    char *qi;
    for (qi = q_right - size; q_left + size < qi; qi -= size) {
        if ((*cmp)(qi, q_left + size) > 0) {
            exch(qi, q_pivot, size);
            q_pivot -= size;
            right_size++;
        }
    }
    //SWAP q_left, q_pivot
    exch(q_left + size, q_pivot, size);

    size_t left_size = n - right_size - 1;

    if (left_size > 0 && right_size > 0){
        if (left_size >= right_size) {
            insertion_sort(base, left_size, size, cmp);
            qsort_median_insert_iter(q_pivot + size, right_size, size, cmp);
        }
        else {
            insertion_sort(q_pivot + size, right_size, size, cmp);
            qsort_median_insert_iter(base, left_size, size, cmp);
        }
    }
}


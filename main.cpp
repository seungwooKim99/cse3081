#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include "my_quick_sorts.h"

using namespace std;

typedef struct {
    unsigned int score;
    float data[3];
    char comments[16];
} ELEMENT;

int my_element_scores_compare(const void *a, const void *b) {
    ELEMENT *rec_a, *rec_b;

    rec_a = (ELEMENT *)a;
    rec_b = (ELEMENT *)b;

    if (rec_a->score == rec_b->score)
        return 0;
    else if (rec_a->score < rec_b->score)
        return -1;
    else
        return 1;
}

void init_ELEMENT_array(ELEMENT *data, int n) {
    // Generate an array with random key sequences.
    int i, j;

    for (i = 0; i < n; i++) {
        data[i].score = i;
        //itoa(i, data[i].comments, 16);    // visual studio에서만 돌아감ㅠㅠ
        sprintf(data[i].comments, "%d", i); // ubuntu에서 동일한 코드
        data[i].data[0] = 2 * i;
    }

    // Shuffle the key values using the Fisher-Yates shuffle algorithm.
    srand((unsigned int)time(NULL));

    for (i = n - 1; i >= 1; i--) {
        j = rand() % (i + 1);

        {
            // codes from qsort.c
            char buf[256];
            char *r_i = (char *)(data + i);
            char *r_j = (char *)(data + j);
            size_t m, ms;

            for (ms = sizeof(ELEMENT); ms > 0; ms -= m, r_i += m, r_j += m) {
                m = ms < sizeof(buf) ? ms : sizeof(buf);

                memcpy(buf, r_i, m);
                memcpy(r_i, r_j, m);
                memcpy(r_j, buf, m);
            }
        }
    }
}

#define N_MAX_ELEMENTS 10240
#define PRINT_DATA

int main() {
    int fnc_num, n;
    int i;
    char *ptr; //strtol pointer
    ELEMENT *Array;

    FILE *fp = fopen("HW2_commands.txt", "r");
    char *buffer = (char *)malloc(256 * sizeof(char));

    char input_name[50], output_name[50];

    //fp = fopen("HW2_commands.txt", "r");
    if ( fp == NULL ){
        printf("File open error.\n");
    }

    fgets(buffer, 256, fp); // 함수의 번호
    fnc_num = strtol(buffer, &ptr, 10);

    fgets(buffer, 256, fp); // n
    n = strtol(buffer, &ptr, 10);

    fgets(input_name, 256, fp); // input
    if (input_name[strlen(input_name) - 1] == '\n'){
        input_name[strlen(input_name) - 1] = '\0';
    }

    fgets(output_name, 256, fp); // output
    if (output_name[strlen(output_name) - 1] == '\n'){
        output_name[strlen(output_name) - 1] = '\0';
    }
    fclose(fp);

    printf("*** Function Number : %d\n", fnc_num);
    printf("*** Array size: %d\n", n);

    Array = (ELEMENT*)malloc(sizeof(ELEMENT)*n);

    // bin에서 읽어오기
    FILE *fp_input = fopen(input_name, "r");
    for(i=0;i<n;i++){
        fread(Array+i, sizeof(ELEMENT), 1, fp_input);
    }
    fclose(fp_input);

    // test에서만 씀!
    //init_ELEMENT_array(Array, n);

#ifdef PRINT_DATA
    printf("* Data before sort: ");
    for (int i = 0; i < n; i++)
        printf(" ([%u], %f, 0%s) ", Array[i].score, Array[i].data[0], Array[i].comments);
    printf("\n\n");
#endif

    switch (fnc_num) {
        case 1 :
            qsort(Array, n, sizeof(ELEMENT), my_element_scores_compare);
            break;
        case 21:
            qsort_orig(Array, n, sizeof(ELEMENT), my_element_scores_compare);
            break;
        case 22:
            qsort_median_insert(Array, n, sizeof(ELEMENT), my_element_scores_compare);
            break;
        case 23:
            qsort_median_insert_iter(Array, n, sizeof(ELEMENT), my_element_scores_compare);
            break;
    }

#ifdef PRINT_DATA
    printf("* Data after sort: ");
    for (int i = 0; i < n; i++)
        printf(" ([%u], %f, 0%s) ", Array[i].score, Array[i].data[0], Array[i].comments);
    printf("\n\n");
#endif

    FILE *fp_output = fopen(output_name, "w");
    for(i=0;i<n;i++){
        fwrite(Array+i, sizeof(ELEMENT), 1, fp_output);
    }
    fclose(fp_output);

    free(Array);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "task.h"
int test(int n){
    int a = 0;
    while (n > 0){
        a += n % 10;
        n /= 10;
    }
    return a;
}
void task(Matrix *matr, Matrix *answer){
    answer->m = matr->m;
    answer->arr_rows = malloc(answer->m * sizeof(struct Line));
    for(int i = 0; i < matr->m; i++){
        int k = test(matr->arr_rows[i].arr_cols[matr->arr_rows[i].n - 1]);
        int t = 0;
        answer->arr_rows[i].arr_cols = malloc(sizeof(int));
        for(int j = 0; j < matr->arr_rows[i].n; j++){
            if (test(matr->arr_rows[i].arr_cols[j]) == k){
                answer->arr_rows[i].arr_cols = realloc(answer->arr_rows[i].arr_cols, (t + 1) * sizeof(int));
                answer->arr_rows[i].arr_cols[t] =  matr->arr_rows[i].arr_cols[j];
                t += 1;
            }
        }
        answer->arr_rows[i].n = t;
    }
}

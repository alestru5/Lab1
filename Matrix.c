#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "Matrix.h"
int getInt(int *a){
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0){
            return 0;
        }
        if (n == 0){
            printf("Введен некоректный символ, повторите попытку:\n");
            scanf("%*[^\n]");
	    scanf("%*c");
        }
    }while(n == 0);
    return 1;
}

int input(Matrix *matr){
    int m;
    do{
        printf("Введите количество строк:");
        if (getInt(&m) == 0){
            return 0;
        }
        if (m < 1){
            printf("Ошибка, повторите попытку:\n");
        }
    }while(m<1);
    matr->m = m;
    matr->arr_rows = malloc(m * sizeof(struct Line));
    for (int i = 0; i < m; i++){
        int n;
        do{
            printf("Введите количество столбцов для %d строки:", i);
            if (getInt(&n) == 0){
                return 0;
            }
            if (n < 1){
                printf("Ошибка, повторите попытку:\n");
            }
        }while(n<1);
        matr->arr_rows[i].n = n;
        matr->arr_rows[i].arr_cols = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++){
            printf("Введите элемент [%d][%d]:", i, j);
            int a;
            if (getInt(&a) == 0){
            	return 0;
	    }
	    matr->arr_rows[i].arr_cols[j] = a;
        }
    }
    return 1;
}
void output(Matrix *matr){
    for (int i = 0; i < matr->m; i++){
        for(int j = 0; j < matr->arr_rows[i].n; j++){
            printf("[%d] ", matr->arr_rows[i].arr_cols[j]);
        }
        printf("\n");
    }
}
void clear(Matrix *matr){
    for (int i = 0; i < matr->m; i++){
        free(matr->arr_rows[i].arr_cols);
    }
    free(matr->arr_rows);
}

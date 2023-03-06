#include <stdio.h>
#include <stdlib.h>
typedef struct Line{
    int n;
    int *arr_cols;
}Line;
typedef struct Matrix{
    int m;
    Line *arr_rows;
}Matrix;
int getInt(int *a){
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0){
            return 0;
        }
        if (n == 0){
            printf("Введен некоректный символ, повторите попытку:");
	    scanf("%*s");
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
	    getInt(&a);
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
int main() {
    Matrix matr = {0, NULL};
    Matrix answer = {0, NULL};
    if (input(&matr) == 0){
        printf("Конец файла");
        return 1;
    }
    printf("Изначальная матрица:\n");
    output(&matr);
    printf("Итоговая матрица:\n");
    task(&matr, &answer);
    output(&answer);
    clear(&matr);
    clear(&answer);
    return 0;
}


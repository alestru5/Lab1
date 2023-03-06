#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "task.h"
#include "Matrix.h"
int main() {
    Matrix matr = {0, NULL};
    Matrix answer = {0, NULL};
    if (input(&matr) == 0){
        printf("Конец файла");
	clear(&matr);
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

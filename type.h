#ifndef TYPE_H
#define TYPE_H
typedef struct Line{
    int n;
    int *arr_cols;
}Line;
typedef struct Matrix{
    int m;
    Line *arr_rows;
}Matrix;
#endif

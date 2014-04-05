#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifndef FOO_H
#define FOO_H
typedef struct matrix_t
{
	int coloums;
	int rows;
	double ** matrix;
} matrix;
#endif
matrix create_matrix(int, int);
void free_matrix(matrix);
matrix add(matrix, matrix);
matrix multiply(matrix, matrix);
void print_matrix(matrix);

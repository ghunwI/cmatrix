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
matrix add(matrix, matrix);
matrix create_matrix(int, int);
void free_matrix(matrix);
int is_equal(matrix, matrix);
int is_same_size(matrix, matrix);
int is_valid(matrix);
matrix join_matrices(matrix,matrix);
matrix multiply(matrix, matrix);
void print_matrix(matrix);

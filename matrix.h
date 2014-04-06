#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifndef MATRIX
#define MATRIX
typedef struct matrix_t
{
	int coloumns;
	int rows;
	double ** matrix;
} matrix;
matrix add(matrix, matrix);
matrix create_matrix(int, int);
void free_matrix(matrix);
int is_equal(matrix, matrix);
int is_same_size(matrix, matrix);
int is_valid(matrix);
matrix join_matrices(matrix,matrix);
matrix multiply(matrix, matrix);
void print_matrix(matrix);
#include "vector.h" //these two headers reference each other. I am not sure how to declare structs before declaring functions for both
#endif

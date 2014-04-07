#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#ifndef MATRIX_STRUCT
#define MATRIX_STRUCT
typedef struct matrix_t
{
	int coloumns;
	int rows;
	double ** matrix;
} matrix;
#endif
#ifndef MATRIX_FUNC
#define MATRIX_FUNC
#include "vector.h" //these two headers reference each other. I am not sure how to declare structs before declaring functions for both
matrix add(matrix, matrix);
matrix create_matrix(int, int);
void free_matrix(matrix);
vector get_coloumn(matrix,int);
vector get_row(matrix,int);
double get_element(matrix,int,int);
int is_equal(matrix, matrix);
int is_same_size(matrix, matrix);
int is_valid(matrix);
matrix join_matrices(matrix,matrix);
matrix multiply(matrix, matrix);
void print_matrix(matrix);
matrix transpose(matrix);
#endif

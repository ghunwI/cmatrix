/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
*/
#include "matrix.h"
/*
typedef struct matrix_t
{
	int coloums;
	int rows;
	double ** matrix;
} matrix;
matrix create_matrix(int, int);
void free_matrix(matrix);
matrix add(matrix, matrix);
matrix multiply(matrix, matrix);
*/

matrix create_matrix(int ro, int co)
{
	matrix m;
	m.rows = ro;
	m.coloums = co;
	m.matrix = malloc(sizeof(double*) * ro);
	int i;
	for(i = 0; i < ro; i++)
	{
		m.matrix[i] = malloc(sizeof(double) * co);
	}
	return m;
}
void free_matrix(matrix m)
{
	int i;
	for(i = 0; i < m.rows; i++)
	{
		free(m.matrix[i]);
	}
	free(m.matrix);
}
matrix add(matrix A, matrix B)//provide add_s to send error messages
{
	matrix AB;
	//if(A.rows != B.rows || A.coloums != B.coloums) {AB.rows=0;AB.coloums=0;return AB }
	int i,j;
	AB = create_matrix(A.rows,A.coloums);
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < A.coloums; j++)
		{
			AB.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}
	return AB;
}
matrix multiply(matrix A, matrix B)
{
	matrix AB;
	//if(A.coloums != B.rows) {AB.rows=0;AB.coloums=0;return AB }
	int i,j,k;
	AB = create_matrix(A.rows,B.coloums);
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < B.coloums; j++)
		{
			AB.matrix[i][j] = 0;
			for(k = 0; k < A.coloums; k++)
			{
				AB.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
			}
		}
	}
	return AB;
}

void print_matrix(matrix m)
{
	int i,j;
	for(i = 0; i < m.rows; i++)
	{
		printf("\n");
		for(j = 0; j < m.coloums; j++)
		{
			printf("%f ", m.matrix[i][j]);
		}
	}
}
	


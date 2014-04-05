/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
*/
#include "matrix.h"
/*
Notes: If a matrix returns
*/
matrix add(matrix A, matrix B)//provide add_s to send error messages
{
	matrix AB;
	#ifdef SAFETY
	if(A.rows != B.rows || A.coloums != B.coloums) {AB.rows=0;AB.coloums=0;return AB; }
	#endif
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
int is_equal(matrix A, matrix B)
{
	if(A.rows != B.rows || A.coloums != B.coloums) { return 0; }
	int i,j;
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < A.coloums; j++)
		{
			if(A.matrix[i][j] != B.matrix[i][j]) { return 0; }
		}
	}
	return 1;
}
int is_same_size(matrix A, matrix B)
{
	if(A.rows != B.rows || A.coloums != B.coloums) { return 0; }
	else { return 1; }
}
int is_valid(matrix m)//This will see if the matrix has any 0 dimensions
{
	if(m.rows == 0 || m.coloums == 0) {return 0;}
	return 1;
}
matrix join_matrices(matrix A, matrix B)//This will take an n*m and n*r matrix and create a n*(m+r) matrix
{	
	matrix AjB;
	int i,j;
	if(A.rows != B.rows){AjB.rows = 0; AjB.coloums = 0; return AjB;}
	AjB = create_matrix(A.rows, A.coloums + B.coloums);
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < A.coloums; j++)
		{
			AjB.matrix[i][j] = A.matrix[i][j];
		}
		for(j = A.coloums; j < AjB.coloums; j++)
		{
			AjB.matrix[i][j] = B.matrix[i][(j-A.coloums)];
		}
	}
	return AjB;
}
matrix multiply(matrix A, matrix B)
{
	matrix AB;
	#ifdef SAFETY
	if(A.coloums != B.rows) {AB.rows=0;AB.coloums=0;return AB; }
	#endif
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
		for(j = 0; j < m.coloums; j++)
		{
			printf("%f ", m.matrix[i][j]);
		}
		printf("\n");
	}
}
	


/*
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
*/
#include "matrix.h"
/*
Notes: If a matrix function returns with a matrix of zero size, then an error occured
*/
matrix add(matrix A, matrix B)//<bar>provide add_s to send error messages</bar>
{
	matrix AB;
	#ifdef SAFETY
	if(A.rows != B.rows || A.coloumns != B.coloumns) {AB.rows=0;AB.coloumns=0;return AB; }
	#endif
	int i,j;
	AB = create_matrix(A.rows,A.coloumns);
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < A.coloumns; j++)
		{
			AB.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}
	return AB;
}
void add_row(matrix A, int row, double factor, int target_row)
{
	int i;for(i=0;i<A.coloumns;i++){A.matrix[target_row][i]+=A.matrix[row][i]*factor;}
}
matrix create_matrix(int ro, int co)
{
	matrix m;
	m.rows = ro;
	m.coloumns = co;
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
	if(A.rows != B.rows || A.coloumns != B.coloumns) { return 0; }
	int i,j;
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < A.coloumns; j++)
		{
			if(A.matrix[i][j] != B.matrix[i][j]) { return 0; }
		}
	}
	return 1;
}
/*matrix gauss(matrix A)//NOT READY
{	//don't try and interpret results
	//This will work recursively: change A such that the first coloum 1 than 0s, and then apply to submatrices to get a diagonal  
	//first we see if the first row is 0
	matrix Ag;
	double zerozero = A.matrix[0][0];
	multiply_row(A.matrix,0,(1.0/zerozero));
	int i;
	for(i = 1; i < A.rows; i++)
	{	
		zerozero = A.matrix[i][0]
		add_row(Ag,0,zerozero,i);
	}
	//Should I copy submatrix, solve then replace, or try and create a submatrix via pointer arithmetic 
}*/
vector get_row(matrix A, int row)
{
	vector v;
	#ifdef SAFETY
	if(row >= A.rows) {v.length = 0; return v;} 
	#endif
	v.length = A.coloumns;
	v.vals = malloc(sizeof(double) * A.coloumns);
	v.vals = memcpy(v.vals, A.matrix[row], sizeof(double) * A.coloumns);
	return v;
}
vector get_coloumn(matrix A, int coloumn)
{
	vector v;
	#ifdef SAFETY
	if(coloumn >= A.coloumns) {v.length = 0; return v;}
	#endif
	int i;
	v.length = A.rows;
	v.vals = malloc(sizeof(double) * A.rows);
	for(i = 0; i < A.rows; i++)
	{
		v.vals[i] = A.matrix[i][coloumn];
	}
	return v;
}
matrix get_submatrix(matrix A, int top, int bot, int left, int right)//do not free_matrix this matrix
{
	matrix Asub;//This also assumes that functions only touch what there supposed to
	A.rows = bot -top;
	A.coloumns = right - left;
	int i;
	for(i = 0; i < A.rows; i++)
	{
		Asub.matrix[i] = A.matrix[top + i] + left;//think this is ok
	}
	return Asub;
}
double get_element(matrix A,int row, int coloumn)// this is a wrapper around matrix notation
{
	#ifdef SAFETY 
	if(row >= A.rows || coloumn >= A.coloumns) {return (0.0/0.0);}
	#endif
	return A.matrix[row][coloumn];
}
int is_same_size(matrix A, matrix B)
{
	if(A.rows != B.rows || A.coloumns != B.coloumns) { return 0; }
	else { return 1; }
}
int is_valid(matrix m)//This will see if the matrix has any 0 dimensions
{
	if(m.rows == 0 || m.coloumns == 0) {return 0;}
	return 1;
}
matrix join_matrices(matrix A, matrix B)//This will take an n*m and n*r matrix and create a n*(m+r) matrix
{	
	matrix AjB;
	int i,j;
	if(A.rows != B.rows){AjB.rows = 0; AjB.coloumns = 0; return AjB;}
	AjB = create_matrix(A.rows, A.coloumns + B.coloumns);
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < A.coloumns; j++)
		{
			AjB.matrix[i][j] = A.matrix[i][j];
		}
		for(j = A.coloumns; j < AjB.coloumns; j++)
		{
			AjB.matrix[i][j] = B.matrix[i][(j-A.coloumns)];
		}
	}
	return AjB;
}
matrix multiply(matrix A, matrix B)
{
	matrix AB;
	#ifdef SAFETY
	if(A.coloumns != B.rows) {AB.rows=0;AB.coloumns=0;return AB; }
	#endif
	int i,j,k;
	AB = create_matrix(A.rows,B.coloumns);
	for(i = 0; i < A.rows; i++)
	{
		for(j = 0; j < B.coloumns; j++)
		{
			AB.matrix[i][j] = 0;
			for(k = 0; k < A.coloumns; k++)
			{
				AB.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
			}
		}
	}
	return AB;
}
void multipy_row(matrix A, int row, double k)
{
	int i;for(i=0;i<A.coloumns;i++){A.matrix[row][i]*=k;}
}
void print_matrix(matrix m)
{
	int i,j;
	for(i = 0; i < m.rows; i++)
	{
		for(j = 0; j < m.coloumns; j++)
		{
			printf("%f ", m.matrix[i][j]);
		}
		printf("\n");
	}
}
matrix transpose(matrix A)//does not affect struct
{
	matrix At;
	int i,j;
	At = create_matrix(A.coloumns, A.rows);
	for(j = 0; j < A.coloumns; j++)
	{
		for(i = 0; i < A.rows; i++)
		{
			At.matrix[i][j] = A.matrix[j][i];
		}
	}
	return A;
}
void switch_rows(matrix A, int row_one, int row_two)
{
	int size = sizeof(double) * A.coloumns;
	double *temp = malloc(size);//can you to dynamically sized arrays
	memcpy(temp,A.matrix[row_one],size);
	memcpy(A.matrix[row_one],A.matrix[row_two],size);
	memcpy(A.matrix[row_two],temp,size);
}

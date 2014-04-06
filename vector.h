#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#ifndef VECTOR
#define VECTOR
#include "matrix.h"
typedef struct vector_t
{
	int length;
	double * vals;
} vector;
vector add_vectors(vector, vector);
vector create_vector(int);
double dot_vectors(vector,vector);
void free_vector(vector);
int is_equal_v(vector, vector);
int is_same_size_v(vector,vector);
int is_valid_vector(vector);
matrix outer_product(vector, vector);
#endif

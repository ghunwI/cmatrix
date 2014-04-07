#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#ifndef VECTOR_STRUCT
#define VECTOR_STRUCT
typedef struct vector_t
{
	int length;
	double * vals;
} vector;
#endif
#include "matrix.h"
#ifndef VECTOR_FUNC
#define VECTOR_FUNC
vector add_vectors(vector, vector);
vector create_vector(int);
double dot_vectors(vector,vector);
void free_vector(vector);
int is_equal_v(vector, vector);
int is_same_size_v(vector,vector);
int is_valid_vector(vector);
matrix outer_product(vector, vector);
#endif

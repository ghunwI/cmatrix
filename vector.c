#include "vector.h"

vector add_vectors(vector v1, vector v2)
{
	vector vsum;
	if(v1.length != v2.length) { vsum.length = 0; return vsum; }
	vsum = create_vector(v1.length);
	int i;
	for(i = 0; i < v1.length; i++)
	{
		vsum.vals[i] = v1.vals[i] + v2.vals[i];
	}
	return vsum;
}
vector create_vector(int size)
{
	vector v;
	v.length = size;
	v.vals = malloc(sizeof(double) * size);
	return v;
}
double dot_vectors(vector v1 ,vector v2)
{
	#ifdef SAFETY
	if(v1.length != v2.length) { return (0.0/0.0); }
	#endif
	int i;
	double product = 0;
	for(i = 0; i < v1.length; i++)
	{
		product += (v1.vals[i] * v2.vals[i]);
	}
	return product;
}
void free_vector(vector v)
{
	free(v.vals);
}
int is_equal_v(vector v1, vector v2)
{
	if(v1.length != v2.length) { return 0; }
	int i;
	for(i = 0; i < v1.length; i++)
	{
		if(v1.vals[i] != v2.vals[i]) { return 0; }
	}
	return 1;
}
int is_same_size_v(vector v1,vector v2)
{
	if(v1.length != v2.length) { return 0; }
	return 1;
}
int is_valid_vector(vector v1)
{
	if(v1.length == 0) { return 0;}
	return 1;
}
matrix outer_product(vector v1, vector v2)//rows v2, coloums v1
{
	int i,j;
	matrix ioj;
	create_matrix(v1.length, v2.length);
	for(i =0; i < v1.length; i++)
	{
		for(j = 0; j < v2.length; j++)
		{
			ioj.matrix[i][j] = (v1.vals[i] * v2.vals[j]);
		}
	}
	return ioj;
}

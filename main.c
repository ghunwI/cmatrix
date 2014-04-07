#include<stdio.h>
#include "matrix.h"
#include "vector.h"
#include "parser.h"
int main(int argn, char * argc[])
{
	char * word = strdup("2,2*2,2");
	char * wordd  = strdup("2,2*2,2");
	matrix one = parse(word,2,2);
	matrix two = parse(wordd,2,2);
	matrix three = add(one,two);
	print_matrix(three);
	matrix m = create_matrix(2,2);
	matrix n = add(m,m);
	free_matrix(m);
	free_matrix(n);
	free_matrix(one);
	free_matrix(two);
	free_matrix(three);
	free(word);
	free(wordd);
	vector v = create_vector(10);
	free_vector(v);
	printf("%lu\n%lu\n", sizeof(vector),sizeof(matrix));
	return 22;
}

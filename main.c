#include<stdio.h>
#include "matrix.h"
#include "parser.h"
int main(int argn, char * argc[])
{
	char * word = strdup("2,2*2,2");
	char * wordd  = strdup("2,2*2,2");
	print_matrix(add(parse(word,2,2),parse(wordd,2,2)));
	return 22;
}

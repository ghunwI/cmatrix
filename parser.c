/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "matrix.h"
*/
#include "parser.h"
#define MAX_ROWS 100
#define MAX_COLOUMS 100

matrix parse(char * str, int rows, int coloumns)
{	
	matrix m = create_matrix(rows,coloumns);
	int i,j;
	char ** tokens = malloc(sizeof(char*) * rows);
	char *** nums = malloc(sizeof(char**) * rows);
	tokens[0] = strtok(str, "*");// WHY CAN'T STRTOK BE LIKE A NORMAL FUNCTION!!!!!!!!!!!;
	nums[0] = malloc(sizeof(char*) * coloumns);	
	for(i = 1; i < rows; i++)
	{
		tokens[i] = strtok(NULL, "*");
		nums[i] = malloc(sizeof(char*) * coloumns);
	}
	for(i = 0; i < rows; i++)
	{	
		nums[i][0] = strtok(tokens[i], ",");
		m.matrix[i][0] = atof(nums[i][0]);
		for(j = 1; j < coloumns; j++)
		{
			nums[i][j] = strtok(NULL, ",");
			m.matrix[i][j] = atof(nums[i][j]);	
		}
	}
	return m;
	//nums should have the number
}

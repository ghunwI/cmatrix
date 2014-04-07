compiler = clang
all:
	$(compiler) main.c matrix.c parser.c vector.c -o matrix -g -Wall -D SAFETY

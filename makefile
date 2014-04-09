compiler = clang
all:
	$(compiler) main.c matrix.c parser.c vector.c -o matrix -O2 -Wall -D SAFETY

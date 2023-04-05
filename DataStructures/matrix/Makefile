test_matrix:
	gcc -O0 -g -Wall  main.c matrix.c test.c -o matrix && ./matrix && valgrind --leak-check=full -s ./matrix

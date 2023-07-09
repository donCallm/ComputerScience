test_prefix_arr:
	g++ -O0 -g -Wall  main.cpp prefix_array.cpp test.cpp -o prefix_array && ./prefix_array
check_leak:
	valgrind --leak-check=full -s ./prefix_array
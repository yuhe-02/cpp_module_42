make re
valgrind --leak-check=full -q ./convert 42.0
valgrind --leak-check=full -q ./convert 42.0f
valgrind --leak-check=full -q ./convert 42
valgrind --leak-check=full -q ./convert 2147483648
valgrind --leak-check=full -q ./convert a
valgrind --leak-check=full -q ./convert "a"
valgrind --leak-check=full -q ./convert "a.0"
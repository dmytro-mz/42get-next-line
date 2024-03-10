#!/bin/bash


echo "Compiling..."
cc -Wall -Wextra -Werror main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=1 -o bonus_1
echo "Testing..."
valgrind --leak-check=full -q ./bonus_1 test_files/a.txt test_files/b.txt > test_out.txt
diff test_files/ab_expected_out.txt test_out.txt
echo "Cleaning..."
rm -rf ./bonus_1 test_out.txt

#!/bin/bash


echo "Compiling..."
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1 -o mandatory_1
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42 -o mandatory_42
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=1000 -o mandatory_1000
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o mandatory_default
echo ""
for prog in mandatory_1 mandatory_42 mandatory_1000 mandatory_default; do
    echo "Testing ${prog}:"
    for test_file in a.txt b.txt empty.txt main.c; do
        echo "${test_file}..."
        valgrind --leak-check=full -q ./${prog} test_files/${test_file} > test_out.txt
        diff test_files/${test_file} test_out.txt
        valgrind --leak-check=full -q ./${prog} < test_files/${test_file} > test_out.txt
        diff test_files/${test_file} test_out.txt
    done
    echo ""
done
echo ""
echo "Cleaning..."
rm -rf ./mandatory_1 ./mandatory_42 ./mandatory_1000 ./mandatory_default test_out.txt

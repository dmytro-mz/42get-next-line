/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    char *s;
    int fd = 0;
    // int fd = open("text.txt", O_RDONLY);
    while ((s = get_next_line(fd)))
        printf("%s", s);
    close(fd);
    return 0;
}

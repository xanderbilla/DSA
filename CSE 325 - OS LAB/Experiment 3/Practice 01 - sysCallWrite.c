//write a program to display some content on console using write system calls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    write(1, "Hello World\n", 5);
    return 0;
}
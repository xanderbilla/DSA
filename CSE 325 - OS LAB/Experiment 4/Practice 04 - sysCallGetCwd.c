#include<stdio.h>
#include<unistd.h>

void main()
{
    char cwd[100];
    getcwd(cwd, 100);
    printf("Current working directory: %s\n", cwd);

    return;
}
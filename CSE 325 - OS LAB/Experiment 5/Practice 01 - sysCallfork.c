//Program to illustrate perform n consecutive fork() system calls generate 2^n child processesprompt user to enter the value of n and display the process id of each child process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        fork();
        printf("Child Process %d with PID: %d\n", i + 1, getpid());
    }

    return 0;
}

/*
Program to utilize the fork() system call to gnerate the following process hierarchy: 
P1 -> P2 -> P3 the program should dis[play the process id of each process and the parent 
process id of each process
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 == 0)
    {
        printf("Child Process 1 with PID: %d and Parent PID: %d\n", getpid(), getppid());
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("Child Process 2 with PID: %d and Parent PID: %d\n", getpid(), getppid());
        }
    }

    return 0;
}
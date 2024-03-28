//create zombie process

#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        printf("Child Process with PID: %d and Parent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        printf("Parent Process with PID: %d\n", getpid());
        sleep(10);
    }

    return 0;
}
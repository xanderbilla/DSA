//Create an orphan process using fork system call. Demonstrate that the child process is adopted by init process.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        printf("Child Process with PID: %d and Parent PID: %d\n", getpid(), getppid());
        sleep(10);
        printf("Child Process with PID: %d and Parent PID: %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent Process with PID: %d\n", getpid());
    }

    return 0;
}
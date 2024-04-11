/*
Program to generate a process hierarchy as follows:

                             P1
                            /  \
                          P2    P3
                        /
                       P4
                       /
                     P5

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t pid1, pid2, pid3, pid4, pid5;

    pid1 = fork();
    if (pid1 == 0)
    {
        printf("Child Process 1 with PID: %d and Parent PID: %d\n", getpid(), getppid());
        pid2 = fork();
        if (pid2 == 0)
        {
            printf("Child Process 2 with PID: %d and Parent PID: %d\n", getpid(), getppid());
            pid4 = fork();
            if (pid4 == 0)
            {
                printf("Child Process 4 with PID: %d and Parent PID: %d\n", getpid(), getppid());
                pid5 = fork();
                if (pid5 == 0)
                {
                    printf("Child Process 5 with PID: %d and Parent PID: %d\n", getpid(), getppid());
                }
            }
        }
        else
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                printf("Child Process 3 with PID: %d and Parent PID: %d\n", getpid(), getppid());
            }
        }
    }

    return 0;
}

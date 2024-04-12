//Write a program to create a pipe and write a message from parent to child using pipes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* Pipe is a system call that is used to create a unidirectional communication channel between two processes.
* It is used to send data from one process to another.
* It is a form of Inter-Process Communication (IPC).
* The pipe system call creates a pipe and returns two file descriptors.
* The first file descriptor is used for reading and the second file descriptor is used for writing.

* Syntax:
* int pipe(int fd[2]);
*/

int main()
{
    int fd[2], n; // fd[0] is for reading and fd[1] is for writing
    char buf[30]; // buffer to store the message
    
    pid_t p; // process id
    pipe(fd); // creating a pipe
    p = fork(); // creating a child process

    if (p > 0)
    {
        printf("In parent process\n");
        close(fd[0]);
        printf("Enter the message to be sent to child: ");
        scanf("%d", buf);
        write(fd[1], buf, 30);
        close(fd[1]);
    }
    else
    {
        printf("In child process\n");
        close(fd[1]);
        n = read(fd[0], buf, 30);
        write(1, buf, n);
        close(fd[0]);
    }
}
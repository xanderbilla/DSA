// Write a program to create named pipe between two processes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    int res;

    /*
    * mkfifo() creates a new FIFO special file, FIFOs are named pipes.
    * The FIFO special file is an interface to a pipe. It has to be open at both ends simultaneously before you can proceed to do any input or output operations on it.
    * Any number of processes can open the file for reading or writing.
    * 
    * The mkfifo() function creates a new FIFO special file, pathname, with mode mode. 
    * If the file already exists, mkfifo() fails with a return value of -1 and errno set to EEXIST.
    */
    res = mkfifo("pipe", 0777);
    if (res == -1) {
        perror("mkfifo");
        exit(1);
    }

    printf("FIFO created\n");
    
    return 0;
}
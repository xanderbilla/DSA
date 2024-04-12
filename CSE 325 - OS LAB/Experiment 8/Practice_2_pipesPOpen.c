// Write a program for wordcount using popen and pclose pipes.

/*
* popen is a system call that is used to create a pipe and execute a command.
* It's return type is a FILE pointer.
* It is used to open a process by creating a pipe, forking, and invoking the shell.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char buffer[100];

    sprintf(buffer, "Yohohoho, he took a bite of gum gum!");

    //sprint is used to store the string in buffer

    // wc -c is used to count the number of characters in the file
    fp = popen("wc -c", "w"); 

    /*
    * fwrite is used to send data in file stream pipe.
    * There are 4 arguments in fwrite:
    * 1. buffer: pointer to the array of elements to be written (What to write in the file stream)
    * 2. 1: size of each element to be written (How to write the data in the file stream)
    * 3. strlen(buffer): number of elements to be written (How many elements to write in the file stream)
    * 4. fp: pointer to the file stream (Where to write the data)
    */

    fwrite(buffer, 1, strlen(buffer), fp);
    pclose(fp);

    return 0;
}
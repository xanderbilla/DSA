//Write a program to update/append a file using open system call

#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>

int main()
{
    char buffer[100];
    // int file = open("test.txt", O_RDONLY);
    // int n = read(file, buffer, 20); // taking 20 characters from the file
    int n = read(0, buffer, 60); // taking 20 characters from user

    int file = open("test.txt", O_WRONLY | O_APPEND); 
    /*
        0777 format is the octal format for the permission of the file

        Extra 0 is added to the front of the number to indicate that it is an octal number

        Read = 4
        Write = 2
        Execute = 1
    */

    //3rd param is the permission for the file when we create it
    
    write(file, buffer, n);

    return 0;
}
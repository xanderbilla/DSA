//Write a program to read from a file and write the same to other file

#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>

int main()
{
    char buffer[100];
    int file = open("test.txt", O_RDONLY);
    int n = read(file, buffer, 20);

    int file2 = open("file.txt", O_CREAT | O_WRONLY, 0777); 
    /*
        0777 format is the octal format for the permission of the file

        Extra 0 is added to the front of the number to indicate that it is an octal number

        Read = 4
        Write = 2
        Execute = 1
    */

    //3rd param is the permission for the file when we create it
    
    write(file2, buffer, n);

    return 0;
}
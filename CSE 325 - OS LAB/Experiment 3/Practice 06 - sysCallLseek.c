//use lseek() to skip the character

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char buffer[100];
    int fd = open("test.txt", O_RDWR);
    /*
        Content of test.txt:
        ---------------------

        Why pass exam when you can just pass away!!!

    */

    read(fd, buffer, 10); // reading 10 characters from the file
    lseek(fd, 10, SEEK_CUR); // skipping 10 characters    
    read(fd, buffer, 10); // reading 10 characters from the file
    write(1, buffer, 10); // writing 10 characters to the console

    return 0;
}
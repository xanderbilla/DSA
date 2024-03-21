/*
Syntax:

int open(const char *pathname, int flags, mode_t mode);

Parameters:
-------------

pathname : Path to the file you want to open.

flags : Flags that specify the file access mode and behavior. Flags can be combined using the Bit-wise OR operator.

mode : Permissions to set if file is created.

Return value:

On success the open function returns a non-negative integer, which is the file descriptor.
On failure, it returns -1 , and you can use the errno variable to determine the specific error.

Here are some common flags that can be used with the open function:

O_RDONLY : Open for read-only
O_WRONLY : Open for write-only
O_RDWR : Open for read and write.
O_CREAT : Create the file if it doesn’t exist.
O_TRUNC : Truncate the file to zero length if it exists.
O_APPEND : Append data to the end of the file.
O_EXCL : Used with O_CREAT , returns an error if the file already exists.

Example:
-----------*/

#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char buffer[100];
    // int file = open("test.txt", O_RDONLY); //miggt return garbage value 
    int file = open("file.txt", O_RDONLY);
    int n = read(file, buffer, 20);

    write(1, buffer, n);

    return 0;
}
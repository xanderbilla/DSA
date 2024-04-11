// Write a program to remove a directory using system call.

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

void main()
{
    int status;
    char dirName[100];

    printf("Enter the name of the directory to remove:");
    scanf("%s", dirName);

    status = rmdir(dirName);

    printf("Directory %s\n", (status == 0) ? "Removed successfully" : "Failed to remove directory");
}
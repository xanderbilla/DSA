//Create a directory using system call

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

void main()
{
    int status;
    char newDir[100];

    printf("Enter the name of the directory to create:");
    scanf("%s", newDir);

    status = mkdir(newDir, 0777);

    printf("Directory %s\n", (status == 0) ? "created successfully" : "creation failed");
}
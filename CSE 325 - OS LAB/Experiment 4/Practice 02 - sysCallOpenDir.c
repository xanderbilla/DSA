//Write a program to list all files in a directory using system call.

#include<stdio.h>
#include<dirent.h>

void main()
{
    DIR *dir = opendir(".");
    struct dirent *entry;
    
    while((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

    return;
}
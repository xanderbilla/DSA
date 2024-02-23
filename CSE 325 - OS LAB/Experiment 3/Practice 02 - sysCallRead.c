//write a program to display read from console and display on console using read 

#include <stdio.h>
#include <unistd.h>

int main()
{
    
    char buffer[100];

    int n = read(0, buffer, 20);
    write(1, buffer, n);

    return 0;
}

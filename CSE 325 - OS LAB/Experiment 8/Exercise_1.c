/*
Exercise 1: Develop a program that demonstrates Inter-Process Communication (IPC) using
named pipes.
    Tasks:
        • Create a pair of named pipes: one for sending data and another for receiving
          data.
        • Develop a sender program that writes a message to the sending pipe.
        • Create a receiver program that reads from the receiving pipe and displays the
          received message.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO1 "fifo1"

int main() {
    if (mkfifo(FIFO1, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }

    char str[100];
    printf("Enter a message: ");
    scanf("%[^\n]", str);

    FILE *fp = fopen(FIFO1, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fprintf(fp, "%s", str);
    fclose(fp);

    return 0;
}
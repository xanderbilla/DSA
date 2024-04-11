//Write a program that creates a thread and passes a message to the thread. The thread should print the message received from the main program.

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *thread(void *arg) // thread function with argument, arg is a void pointer to accept any type of argument 
{
    printf("Thread created successfully\n");
    printf("Message from main program: %s\n", (char *)arg); // typecast the argument to char pointer
    return NULL;
}

void main()
{
    pthread_t tid;
    char message[] = "Hello, thread!";
    pthread_create(&tid, NULL, thread, (void *)message); //(void *)message is the argument to the thread function
    pthread_join(tid, NULL);
    printf("Thread terminated\n");
}
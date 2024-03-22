//create a thread and pass a message to it from the main program to the thread

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *thread(void *arg)
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
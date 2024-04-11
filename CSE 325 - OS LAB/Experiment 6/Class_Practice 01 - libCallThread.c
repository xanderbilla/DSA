//write a program to create a thread using pthread_create() and pthread_join() functions. The thread should print a message "Thread created successfully" and the main thread should print "Thread terminated".

#include<stdio.h>
#include<pthread.h>

void *thread(void *arg)
{
    printf("Thread created successfully\n");
    return NULL;
}

void main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, NULL);
    printf("Thread terminated\n");
}
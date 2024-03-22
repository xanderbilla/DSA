//create a thred

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
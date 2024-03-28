//create a program where a thread return a value to the main program

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define NUMTHREAD 1

void *thread(void *arg)
{
    int *num = (int *)arg;
    int *result = (int *)malloc(sizeof(int));
    *result = *num * *num;
    return (void *)result;
}

void main()
{
    pthread_t tid;
    int num = 5;
    int *result;

    pthread_create(&tid, NULL, thread, (void *)&num);
    pthread_join(tid, (void *)&result);

    printf("Result from the thread: %d\n", *result);
    free(result);
    printf("Thread terminated\n");
}
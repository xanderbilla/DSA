//create a thred

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int i, j;

void *thread(void *arg)
{
    printf("Thread created successfully\n");    

    for(j = 30; j <= 35; j++){
        printf("j = %d\n", j);
        sleep(1);
    }
}

void main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, NULL); // wait for the thread to terminate

    printf("Inside main program\n");

    for(i = 20; i <= 25; i++){
        printf("i = %d\n", i);
        sleep(1);
    }

    printf("Thread terminated\n");
}
//Create a pthread program to find the length of strings passed to the thread function.

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *thread(void *arg)
{
    char *str = (char *)arg;
    int len = 0;

    while(str[len] != '\0'){
        len++;
    }

    printf("Length of the string: %d\n", len);
    return NULL;
}

void main()
{
    pthread_t tid;
    char message[] = "Hello, thread!";
    pthread_create(&tid, NULL, thread, (void *)message);
    pthread_join(tid, NULL);
    printf("Thread terminated\n");
}
//program using pthread_ccreate to generate multiple thread. Each thread should display its own thread id and execution sequence

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

void *display(void *arg)
{
    int *id = (int *)arg;
    printf("Thread ID: %d\n", *id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX];
    int thread_id[MAX];
    for (int i = 0; i < MAX; i++)
    {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, display, (void *)&thread_id[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
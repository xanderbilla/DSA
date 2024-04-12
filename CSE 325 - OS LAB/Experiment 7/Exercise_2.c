/*
Exercise 2: Implement the reader-writer problem using semaphore and mutex operations to synchronize n readers active in the reader section at the same time and one writer active
at a time.

Constraints:
(a) If n readers are active, no writer is allowed to write.
(b) If one writer is writing, no other writer should be allowed to read or write on
the shared variable.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize the mutex variable

void *reader(void *arg)
{
    int item;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (in == out)
        {
            printf("Buffer is empty\n");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        item = buffer[out];
        printf("Reader read item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
    }
}

void *writer(void *arg)
{
    int item;
    while (1)
    {
        item = rand() % 100; // generate a random number
        pthread_mutex_lock(&mutex);
        if (((in + 1) % BUFFER_SIZE) == out)
        {
            printf("Buffer is full\n");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        buffer[in] = item;
        printf("Writer wrote item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, reader, NULL);
    pthread_create(&tid2, NULL, writer, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
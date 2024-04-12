/*
Exercise 1: Implement the producer-consumer problem using pthreads and mutex operations.
Constraints:

(a) A producer only produces if the buffer is empty, and the consumer only consumes
if some content is in the buffer.
(b) A producer writes an item into the buffer, and the consumer deletes the last
produced item in the buffer.
(c) A producer writes on the last consumed index of the buffer.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
pthread_mutex_t mutex;
pthread_cond_t buffer_empty, buffer_full;

void *producer(void *arg)
{
    int item;
    while (1)
    {
        item = rand() % 100; // generate a random number
        pthread_mutex_lock(&mutex);
        if (((in + 1) % BUFFER_SIZE) == out)
        {
            printf("Buffer is full\n");
            pthread_cond_wait(&buffer_full, &mutex);
            continue;
        }
        buffer[in] = item;
        printf("Producer produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        pthread_cond_signal(&buffer_empty);
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *arg)
{
    int item;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (in == out)
        {
            printf("Buffer is empty\n");
            pthread_cond_wait(&buffer_empty, &mutex);
            continue;
        }
        item = buffer[out];
        printf("Consumer consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        pthread_cond_signal(&buffer_full);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&buffer_empty, NULL);
    pthread_cond_init(&buffer_full, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&buffer_empty);
    pthread_cond_destroy(&buffer_full);

    return 0;
}

// Write a program to use mutex to handle process synchronization

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 *   mutex_init(pthread mutex t* mutex, const pthread mutexattr t *attr); //initialize mutex
 *   mutex_lock(pthread_mutex_t *mutex); //Lock a mutex
 *   mutex_unlock(pthread_mutex_t *mutex); //unlock a mutex
 *   mutex_destroy(pthread_mutex_t *mutex); //destroys the mutex
 */

pthread_mutex_t mutex; // mutex variable
int shared = 2;

void *increment(void *arg);
void *decrement(void *arg);


void *increment(void *arg){
    int x;
    pthread_mutex_lock(&mutex);

    x = shared;

    printf("Thread read the value of shared as %d\n", x);

    x++;

    printf("Thread incremented the value of shared to %d\n", x);
    sleep(1);
    shared = x;

    printf("Thread wrote the value of shared as %d\n", x);
    pthread_mutex_unlock(&mutex);
}

void *decrement(void *arg){
    int x;
    pthread_mutex_lock(&mutex);
    x = shared;

    printf("Thread read the value of shared as %d\n", x);

    x--;

    printf("Thread decremented the value of shared to %d\n", x);
    sleep(1);
    shared = x;

    printf("Thread wrote the value of shared as %d\n", x);
    pthread_mutex_unlock(&mutex);
}

int main()
{
    // initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // declare two threads
    pthread_t tid1, tid2; 

    pthread_create(&tid1, NULL, increment, NULL);
    pthread_create(&tid2, NULL, decrement, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Final value of shared: %d\n", shared);
    pthread_mutex_destroy(&mutex); // destroy the mutex
}

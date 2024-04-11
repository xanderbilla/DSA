// Write a program to handle process synchronization the previous program using semaphore

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h> //headerfile for semaphore

/*
 *   sem_init(address_of_semaphore_var, 0, initial_value); //initial_value is the number of threads that can access the shared resource at a time
 *   sem_wait(address_of_semaphore_var); //decrements the semaphore value by 1
 *   sem_post(address_of_semaphore_var); //increments the semaphore value by 1
 *   sem_destroy(address_of_semaphore_var); //destroys the semaphore
 */

void *increment(void *arg);
void *decrement(void *arg);
sem_t s; // semaphore variable
int shared = 2;

int main()
{
    // Initialize the semaphore
    sem_init(&s, 0, 1);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, increment, NULL);
    pthread_create(&tid2, NULL, decrement, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Final value of shared: %d\n", shared);
    sem_destroy(&s); // Destroy the semaphore
}

void *increment(void *arg)
{
    int x;
    sem_wait(&s);

    x = shared;

    printf("Thread read the value of shared as %d\n", x);

    x++;

    printf("Thread incremented the value of shared to %d\n", x);
    sleep(1);
    shared = x;

    printf("Thread wrote the value of shared as %d\n", x);
    sem_post(&s);
}

void *decrement(void *arg)
{
    int x;
    sem_wait(&s);
    x = shared;

    printf("Thread read the value of shared as %d\n", x);

    x--;

    printf("Thread decremented the value of shared to %d\n", x);
    sleep(1);
    shared = x;

    printf("Thread wrote the value of shared as %d\n", x);
    sem_post(&s);
}
}

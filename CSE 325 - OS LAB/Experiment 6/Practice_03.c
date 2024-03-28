/*

Implement a program that performs statistical operation that is calculating average maximum and minimum for a set of
numbers utilize three thirds where each thread perform its respective operation

*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUMTHREAD 3 // number of threads

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int avg, max, min;

void *average(void *arg)
{

    // average = sum of all elements / number of elements

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    avg = sum / 10;
    printf("Average: %d\n", avg);
    return NULL;
}

void *maximum(void *arg)
{
    max = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Maximum: %d\n", max);
    return NULL;
}

void *minimum(void *arg)
{
    min = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Minimum: %d\n", min);
    return NULL;
}

void main()
{
    pthread_t tid[NUMTHREAD]; // array of thread identifiers
    pthread_create(&tid[0], NULL, average, NULL);
    pthread_create(&tid[1], NULL, maximum, NULL);
    pthread_create(&tid[2], NULL, minimum, NULL);

    for (int i = 0; i < NUMTHREAD; i++)
    {
        pthread_join(tid[i], NULL);
    }

    printf("Thread terminated\n");
}
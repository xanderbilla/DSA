/*
Write a multi thread program where a globally passed array of integer is divided into smaller list and grew given up as input to 2THREADS each thread sorts their half of the list and then passes the sorted list to the 3rd thread which merges and sorts them the final sorted list is printed by the parent thread

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

int arr[MAX] = {10, 29, 98, 71, 64, 55, 46, 39, 12, 61};

void *sort(void *arg)
{
    int *arr = (int *)arg;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    pthread_exit((void *)arr);
}

void *merge(void *arg)
{
    int *arr1 = (int *)arg;
    int *arr2 = (int *)arg;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int *arr = (int *)malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    pthread_exit((void *)arr);
}

int main()
{
    pthread_t threads[3];
    int *arr1 = (int *)malloc(MAX / 2 * sizeof(int));
    int *arr2 = (int *)malloc(MAX / 2 * sizeof(int));
    for (int i = 0; i < MAX / 2; i++)
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i + MAX / 2];
    }
    pthread_create(&threads[0], NULL, sort, (void *)arr1);
    pthread_create(&threads[1], NULL, sort, (void *)arr2);
    pthread_join(threads[0], (void **)&arr1);
    pthread_join(threads[1], (void **)&arr2);
    pthread_create(&threads[2], NULL, merge, (void *)arr1);
    pthread_join(threads[2], (void **)&arr1);
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}
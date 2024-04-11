//Write a program to demonstrate race condition with one increment and one decrement function using pthread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *increment(void *arg);
void *decrement(void *arg);

int shared = 2;

int main(){
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, increment, NULL);
    pthread_create(&tid2, NULL, decrement, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Final value of shared: %d\n", shared);
}

void *increment(void *arg){
    int x;
    x = shared;

    printf("Thread read the value of shared as %d\n", x);

    x++;

    printf("Thread incremented the value of shared to %d\n", x);
    sleep(1);
    shared = x;

    printf("Thread wrote the value of shared as %d\n", x);

}

void *decrement(void *arg){
    int x;
    x = shared;

    printf("Thread read the value of shared as %d\n", x);

    x--;

    printf("Thread decremented the value of shared to %d\n", x);
    sleep(1);
    shared = x;

    printf("Thread wrote the value of shared as %d\n", x);
}

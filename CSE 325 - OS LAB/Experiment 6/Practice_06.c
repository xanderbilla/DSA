//threaded applocation that demonstrate graceful thread termination using pthread_exit for resource cleanup compared to abrupt termination via pthread_exit

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunction(void *arg){
    printf("Thread Function\n");
    pthread_exit(NULL);
}

int main(){
    pthread_t thread;
    pthread_create(&thread, NULL, threadFunction, NULL);
    pthread_join(thread, NULL);
    printf("Main Function\n");
    return 0;
}
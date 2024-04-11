// Program using pthread to concatenate multiple strings passes to the thread function

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

void *concatenate(void *str)    {
    char *s = (char *)str;
    printf("%s\n", s);
    pthread_exit(NULL);
}
 
int main()
{
    pthread_t threads[MAX];
    char *str[MAX] = {"Hello", "World", "This", "is", "a", "test"};
    for (int i = 0; i < MAX; i++)
    {
        pthread_create(&threads[i], NULL, concatenate, (void *)str[i]);
    }

    for (int i = 0; i < MAX; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
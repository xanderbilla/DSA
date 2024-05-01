/*
Exercise 2: Demonstrate the usage of Shared Memory for IPC.
Tasks:
• Create a shared memory segment and attach it to multiple processes.
• Develop a producer-consumer model, where one process writes data into the
  shared memory, and another process reads from it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_KEY 12345

int main() {
    key_t key = SHM_KEY

    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *data = (char *)shmat(shmid, (void *)0, 0);

    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    if (fork() == 0) {
        printf("Child process: %d\n", getpid());
        printf("Enter data: ");
        scanf("%s", data);
        printf("Data written by child process: %s\n", data);
    } else {
        wait(NULL);
        printf("Parent process: %d\n", getpid());
        printf("Data read by parent process: %s\n", data);
    }

    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}
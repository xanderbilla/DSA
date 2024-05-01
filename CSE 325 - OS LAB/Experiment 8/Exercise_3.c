/*
Exercise 3: Explore IPC using Message Passing techniques.
Tasks:
• Design two processes where one process sends a signal to another process.
• Develop signal handlers in both processes to manage incoming signals and 
  perform specific actions based on the received signal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <signal.h>
#include <unistd.h>

#define MSG_KEY 12345

struct msg_struct {
    long msg_type;
    char msg_text[100];
};

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Process %d received SIGUSR1 signal\n", getpid());

        key_t key = MSG_KEY;
        int msgqid = msgget(key, IPC_CREAT | 0666);
        if (msgqid == -1) {
            perror("msgget");
            exit(1);
        }

        struct msg_struct msg;
        msg.msg_type = 1;
        strcpy(msg.msg_text, "Signal received!");
        if (msgsnd(msgqid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(1);
        }
    }
}

int main() {
    if (fork() == 0) { 
        if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
            perror("signal");
            exit(1);
        }
        while (1) {
            pause(); 
        }
    } else {
        sleep(1); 
        kill(getpid(), SIGUSR1);

        sleep(1);
    }

    return 0;
}

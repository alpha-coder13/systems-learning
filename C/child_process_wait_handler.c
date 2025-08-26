#include <sys/wait.h>
#include <string.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<stdio.h>

#ifndef EXIT_FAILURE
    #define EXIT_FAILURE -1;
#endif
#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0;
#endif
// #include "print_wait_status.h"
int getInt(char *arg, int flag , char *msg){
    return  strtol(arg, NULL, 10);
}
void printWaitStatus(char *msg, int status){
    if (msg != NULL)
        printf("%s", msg);

    if (WIFEXITED(status)) {
        printf("child exited, status=%d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("child killed by signal %d (%s)",WTERMSIG(status), strsignal(WTERMSIG(status)));
        #ifdef WCOREDUMP
            if (WCOREDUMP(status))
                printf(" (core dumped)");
        #endif
        printf("\n");
    } else if (WIFSTOPPED(status)) {
        printf("child stopped by signal %d (%s)\n",WSTOPSIG(status), strsignal(WSTOPSIG(status)));
        #ifdef WIFCONTINUED
    } else if (WIFCONTINUED(status)) {
        printf("child continued\n");
        #endif
    } else {
        /* Should never happen */
        printf("what happened to this child? (status=%x)\n",
        (unsigned int) status);
    }
}
int main(int argc, char *argv[])
{
    int status;
    pid_t childPid;
    if (argc > 1 && strcmp(argv[1], "--help") == 0)
        printf("%s [exit-status]\n", argv[0]);

    switch (fork()) {
    case -1: printf("fork");
    case 0:
        printf("Child started with PID = %ld\n", (long) getpid());
        if (argc > 1)
             exit(getInt(argv[1], 0, "exit-status"));
        else
            for (;;)
                pause();
        exit(EXIT_FAILURE);
    default:
        for (;;) {
        childPid = waitpid(-1, &status, WUNTRACED
                #ifdef WCONTINUED
                | WCONTINUED
                #endif
                );
        if (childPid == -1)
            printf("waitpid");
        
        printf("waitpid() returned: PID=%ld; status=0x%04x (%d,%d)\n",(long) childPid,(unsigned int) status, status >> 8, status & 0xff);
            printWaitStatus(NULL, status);
        
        if (WIFEXITED(status) || WIFSIGNALED(status))
            printf("child exited, status=%d\n, processid : %d", WEXITSTATUS(status),getpid()); // runs at parent at term signals'
            exit(EXIT_SUCCESS);
        }
    }
}
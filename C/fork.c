#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
    int stackid = 211;

    pid_t child;

    switch(child = fork()){
        case -1 :
            printf("error");
            break;
        case 0:
            stackid*=33;
            // exit(2);
            break;
        default :
            break;
    }

    // wait(2);
    printf("pid : %ld, stackid : %d\n",(long)getpid(),stackid);
    return 1;
}
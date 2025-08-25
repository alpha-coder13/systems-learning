#include<fcntl.h>
int main(int argc, char *argv[]){
    
    
    fork();
    fork();
    fork();
    printf("child process :%d of parent :%d\n",getpid(),getppid());

    return 0;
}
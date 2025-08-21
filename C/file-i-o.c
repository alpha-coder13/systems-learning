
#include<stdio.h>
#include<unistd.h> // contains posix declaration for file descriptions
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char *agrv[]){
    // example of file open

    int fileOpen ;

    fileOpen = open("urfunctions_learning.c",O_RDONLY);
/// since the flags is set to O_RDONLY (read only , it will not create a new file)


    if(fileOpen == -1){
        printf("Error reading file");
    }else{
        printf("%d \t file opened successfully", fileOpen);
    }


    if(close(fileOpen)==-1)printf("error closing file");

    fileOpen = open("urdunctions_learning.c", O_RDWR|O_CREAT |O_TRUNC );
    // O_TRUNC : causes the exsisting file to be truncated to zero  : 
    // file permissions should be set other wise will get error while opening the file.

    // Open function flags chan be ORed(|) with each other {they are bitmasks}
    // the data table is found in page 74 TLPI 

    if(fileOpen == -1){
        printf("Error reading file");
    }else{
        printf("%d \t file opened successfully", fileOpen);
    }
    return 0;
}
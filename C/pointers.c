#include<stdio.h>
int main(){
    int a =  1;
    int * pointer_to_a = &a;

    a +=1;
    printf("this is a %d",a);
    *pointer_to_a +=1; // dereferencing a pointer


    printf("this is pointer incremented a %d",a);
}
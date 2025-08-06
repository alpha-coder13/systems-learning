#include<stdio.h>
int main(){
    int a =  1;
    int * pointer_to_a = &a;

    a +=1;
    printf("this is a %d",a);
    *pointer_to_a +=1; // dereferencing a pointer


    printf("this is pointer incremented a %d",a);

    int array[9] = {0,1,2,3,4,5,6,7,8};

    int *pointer_to_array = array;
    int arrayLength = sizeof(array)/sizeof(array[0]);
    
    for(int i =0 ; i< arrayLength;i++){
        printf("array elements %d\n",*(pointer_to_array+i));
    }
    return 0;
}
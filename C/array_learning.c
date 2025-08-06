#include<stdio.h>
int main(){
    int arr[10]; // already allocated memory to the array : memory location present /stored in arr i.e arr is pointer to the first memory address of the array
    printf("array memory location %d",arr); // what is %ls

    // setting array value can be done in may ways 

    arr[10] = 90; // should throw error;
    printf("array value at 10 %d",arr[10]);
    //     *** stack smashing detected ***: terminated
    // Aborted (core dumped)
    // the arr pointer has been allocated a buffer of 10 memory but it  is trying to write to the 11 unit
    // you can read out of bounds but you must write to the memory present in the buffer
    // the above error should happen bellow as well

    int k = 10;
    int *pointer_to_k = &k;

    *(pointer_to_k + 9) = 100;
    printf("array value at 10 %d",*(pointer_to_k + 9));
    // No , not a single error did occur
    /**
        why ?  supposedly there was no allocated buffer (contigous memory location)
        to be thought about
    */

    return 0;
}
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

    // instance of a c-string 

    char k = 's';
    char *pointer_to_k = &k; // the pointer to k locates memory address of k

    // we can also say

    char arrayOfChars[9] = {'a','b','c','d','e','f','g','h','i'};
    int arrayCharLength = sizeof(arrayOfChars)/sizeof(arrayOfChars[0]);

    for(int i = 0 ; i < arrayCharLength ; i++){
        printf("%c",*(arrayOfChars+i));
    }

    // you get the string abcdefghi
    // when you say you have a reference to the pointer of character arrays , the pointer only points to first memory address.

    // arrayOfChars[9] = "abcdefghi\0"; 
    /**
        the above line throws error 
        pointers.c:39:21: warning: assignment to ‘char’ from ‘char *’ makes integer from pointer without a cast [-Wint-conversion]
        39 |     arrayOfChars[9] = "abcdefghi\0";

        
    */
     char *arrayOfChars1 = "abcdefghi"; 
    // here in above the arrayOfChars1 points to address of 'a' the next are just carried on
     for(int i = 0 ; *(arrayOfChars1 +i) != '\0' ; i++){ // another way to iterate strings
        printf("%c",*(arrayOfChars1+i));
    }

    return 0;
}
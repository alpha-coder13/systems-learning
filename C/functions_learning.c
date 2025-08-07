#include<stdio.h>
#include<stdlib.h> // for qsort function // will implement here only to theorize the flow.

// the functions should be defined first in header file or in the code flow , I am defining here in the code flow
void printMyNAme(char *);// this takes a pointer to a string and prints my name
int ComparatorFunc(const void*, const void*); // this is the standard comparator function def

int main(){ // this is also a function // that gets invoked inintitally
    char * a = "Amardeep Saha";
    printMyNAme(a);

    ///  importat topic , function as a pointer;

    int numArr[] = {1,6,5,4,22,10,2,6,2};


    int (*fptr)(const void*, const void*) = &ComparatorFunc; // pointer ot a function
    // syntax :  return_type (*pointer)(... type of parameters ) =  address to the function name;
    qsort(numArr,sizeof(numArr)/sizeof(*numArr),sizeof(numArr[0]), ComparatorFunc);

    for(int i = 0; i <  sizeof(numArr)/sizeof(*numArr); i++){
        printf("%d ",*(numArr+i));
    }
    return 0;
}

void printMyNAme(char * name){
    printf("%s", name);
    return ;
}

int ComparatorFunc(const void * a, const void * b){

    return (*(int*)a) - (*(int*)b); // guide at compar function in cpp ref;
    // (Mytype *)void* => converts a void pointer to pointer of Mytype;

}


#include<stdio.h>
#include<stdlib.h> // for qsort function // will implement here only to theorize the flow.

// the functions should be defined first in header file or in the code flow , I am defining here in the code flow
void printMyNAme(char *);// this takes a pointer to a string and prints my name
int ComparatorFunc(const void*, const void*); // this is the standard comparator function def
int a1(int a, int b,int i);
int a2(int a, int b,int i);
int a3(int a, int b,int i);
int a4(int a, int b,int i);
int a5(int a, int b,int i);

int main(){ // this is also a function // that gets invoked inintitally
    char * a = "Amardeep Saha";
    printMyNAme(a);

    ///  importat topic , function as a pointer;

    int numArr[] = {1,6,5,4,22,10,2,6,2};


    int (*fptr)(const void*, const void*) = &ComparatorFunc; // pointer ot a function
    // syntax :  return_type (*pointer_name)(... type of parameters ) =  address to the function name;
    qsort(numArr,sizeof(numArr)/sizeof(*numArr),sizeof(numArr[0]), fptr);

    for(int i = 0; i <  sizeof(numArr)/sizeof(*numArr); i++){
        printf("%d ",*(numArr+i));
    }

    // array of pointers to functions:
     
    void* fnArr[]  = {&a1,  &a2, &a3, &a4, &a5};
    int size = sizeof(fnArr)/sizeof(*fnArr);

    for(int i =0 ; i < size ; i++){
        int (*fptr)(int,int,int) = *(fnArr+i);
        printf("%d\n", (*fptr)(i+1,i+2,i));
    }


    // or

    for(int i =0 ; i < size ; i++){
        // int (*fptr)(int,int,int) = *(fnArr+i);
        // printf("%d\n", (*fptr)(i+1,i+2,i));

        printf("%d\n",(*((int (*)(int,int,int))(*(fnArr+i))))(i+1,i+2,i));
    }    

    // or

    int (*fnArr2[])(int,int,int)  = {&a1,  &a2, &a3, &a4, &a5};
    // or
    //  int (**fnArr2)(int,int,int)  // for this we would require malloc and free, next time

    int size2 = sizeof(fnArr2)/sizeof(*fnArr2);

    for(int i =0 ; i < size ; i++){
        printf("%d\n",(**(fnArr2 + i))(i+1,i+2,i));
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

int a1(int a, int b,int i){
    return (a * i + b*i); 
}

int a2(int a, int b,int i){
    return (a * i + b*i); 
}
int a3(int a, int b,int i){
    return (a * i + b*i); 
}
int a4(int a, int b,int i){
    return (a * i + b*i); 
}
int a5(int a, int b,int i){
    return (a * i + b*i); 
}

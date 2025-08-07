#include<stdio.h>

// struct IMemployee{
//     int age;
//     char* name;
//     char* designation; // structs can contain pointers as well , here the pointer is to a string;
// };

// can also be written as;

typedef struct{
    int age;
    char* name;
    char* designation; // structs can contain pointers as well , here the pointer is to a string;
} IMemployee;

// void PrintIMemployee(struct IMemployee a){
// can also be written as
void PrintIMemployee(IMemployee a){

    printf("My name is: %s\n",a.name); // pointer to a string , can print a string with %s in printf , why , when , need to implement it mannually
    printf("My age is %d\n",a.age);
    printf("My designation is %s\n",a.designation);
}

int main(){
    // struct IMemployee a;
    // can also be written as 
    IMemployee a;
    a.name = "Amar";
    a.designation = "Engineer";
    a.age = 24;
    PrintIMemployee(a);
    return 0;
}
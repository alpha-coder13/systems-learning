#include<stdio.h>

int main(){
  // definition of strings
  char * name = "Jhon jabocs" ;
  
//   the name pointer points to the memory address of the first letter J 

// the above type of strings are immutable, to make a mutable string we should use the below representation

for(int i = 0 ;*(name+i)!='\0';i++){
    printf("%c",*(name+i));
    printf("%c",name[i]);
}

// the below code should throw err

// name[2] = 'P';   // throws :Segmentation fault (core dumped)
// *(name+2) = 'L'; // also throws error. why ?

 printf("%s", name); 

 char name2[] = "John Jacobs";
 name2[3] = 'L';
 printf("%s", name2); // prints JohL Jacobs



 return 0;
}
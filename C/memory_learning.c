#include<stdio.h>
#include<string.h> //  has the tring functions
#include<stdlib.h>
#include<ctype.h>
int main(void){
    int n = 50;
    // * : dereference operator
    // & : address of operator
    // %p : print the pointers
    int *p =&n; 
    // printf("%p" , &n);



    /// malloc 

    char s[1000];
    scanf("%4s", s);// length to be taken input
    printf("%s",s);
    char *t = malloc(strlen(s)+1) ;// input is size of the string s;

    if(t == NULL){
        return 1;
    }
    for(int i = 0 , n = strlen(s); i <=n ; i++){
        *(t+i) = *(s+i);
    }

    if(strlen(t) > 0){
        t[0] = toupper(t[0]);
    }
    printf("%s",t);
    free(t);
    return 0;

}
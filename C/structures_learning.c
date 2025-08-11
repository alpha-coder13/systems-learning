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


// ------------------------------- struct heavy -----------------------------//

//mordern C pdf 
struct rat {
bool sign;
size_t num;
size_t denom;
};

rat rat_get(signed sign, size_t num, size_t denom) [[__unsequenced__]] {
rat ret = {
.sign = (sign < 0),
.num = num,
.denom = denom,
};
return ret;
}

rat rat_get_normal(rat x) [[__unsequenced__]] {
    size_t c = gcd(x.num, x.denom);
    x.num /= c;
    x.denom /= c;
    return x;
}
rat rat_get_extended(rat x, size_t f) [[__unsequenced__]] {
    x.num *= f;
    x.denom *= f;
    return x;
}
rat rat_get_prod(rat x, rat y) [[__unsequenced__]] {
    rat ret = {
    .sign = (x.sign != y.sign),
    .num = x.num * y.num,
    .denom = x.denom * y.denom,
    };
return rat_get_normal(ret);
}


/*
[Exs 21]Implement function rat_print as declared in listing 10.1. This function should use -> to access the
members of its rat* argument. The printout should have the form ±nom/denum.
[Exs 22]Implement rat_print_normalized by combining rat_normalize and rat_print.

need to do this
*/
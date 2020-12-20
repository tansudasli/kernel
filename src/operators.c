#include <stdio.h>

//gcc -o out/operators src/operators.c && out/operators
int main(int argc, char const *argv[])
{
    /* code */
    int z = 9;
    int a = 10;
    int b = 9;

    printf("z=%d, ++z=%d \n", z, ++z); //9, 10 !!
    printf("a=%d, a++=%d --> a=%d \n", a, a++, a); //10, 10 but became 11, 11
 
    //if (a == 11) {} else {}
    a == 11 ? printf("XI \n") : printf("X \n");

    //a = a+b
    a += b;
    printf("a+b=%d", a);                //20

    return 0;
}

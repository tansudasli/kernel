#include <stdio.h>

//define and initialize. length is automatically set
int intArray[] = {1,2,3,4,5};                          //no need to set explicitly intArray[5]
double doubleArray[] = {2.1, 2.3, 2.4, 2.5};

//[] has * implicitly! so *[] == **
char charArray[] = {'h', 'e', 'l', 'l', 'o', '\0' };   //no need to define /0
char charArray2[] = "world";    //string in fact
char *string = "Hello";         //string or char array.
char *stringArray[] = {"Abidin", "Denyo", "Veli", "Deli"};             //string Array, **string =  char *string[];
//char **stringArray2 = stringArray;

//multi dimension
int grid [3][5] = {
        {1,   2,   3,   4,   5 },
        {6,   7,   8,   9,   10},
        {11,  12,  13,  14,  15}
};

//gcc -o out/arrays src/arrays.c  && out/arrays
int main(int argc, char const *argv[]) {

    for (int i = 0; i < 5; i++) {
        printf("%d \n", intArray[i]);
    }

    //
    for (int i = 0; i < 5; i++) {
        printf("%c \t", string[i]);
    }

    printf("\n%s\n", string);

    for (int i = 0; i < 4; i++) {
//        printf("%s \t", stringArray2[i]);
        printf("%s \t", stringArray[i]);
    }

    //3x5 array/matrix
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 5; ++j) {
            printf("%d\t", grid[i][j]);
        }
    }

    return 0;
}

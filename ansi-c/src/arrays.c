#include <stdio.h>
#include <string.h>

//
int intArray[] = {1,2,3,4,5};                          //no need to set explicitly intArray[5].
double doubleArray[] = {2.1, 2.3, 2.4, 2.5};

//char arrays
char charArray[] = {'h', 'e', 'l', 'l', 'o' };   //no need to define /0. This is same as below line !!!
char charArray2[] = "world where";    //string, and char array!
                                      // do not think it is a string array due to SPACE
                                      // immutable
char *string = "Hello";               //string or char array.
                                      //mostly same, but minor diff. b/w *string and char[] !!!!!
                                      //mutable

//string arrays
char *stringArray[] = {"Abidin", "Denyo", "Veli", "Deli"};    //string Array, **string =  char *string[];
//char **stringArray2 = ; //todo: initialize **string

//multi dimension arrays
int grid [3][5] = {
        {1,   2,   3,   4,   5 },
        {6,   7,   8,   9,   10},
        {11,  12,  13,  14,  15}
};

char xrid [3][5] = {
        {'h',  'e',  'l',  'l',  'o' },
        {'a',  'b',  'i',  'd',  'o'},
        {'h',  'o',  'w',  'y',  'd'}
};

char *srid [2][3] = {
        {"hello",  "agent",  "007"},
        {"how",  "you",  "doing"}
};

//gcc -o out/arrays src/arrays.c  && out/arrays
int main(int argc, char const *argv[]) {

    for (int i = 0; i < 5; i++) {
        printf("%d \n", intArray[i]);
    }

    //
    for (int i = 0; i < strlen(string); i++) {
        printf("%c \t", string[i]);
    }

    printf("\n%s\n", string);

    for (int i = 0; i < 4; i++) {
//        printf("%s \t", stringArray2[i]);
        printf("%s \t", stringArray[i]);
    }

    printf("\n--------char[][] and int[][] and *string[][]------------\n");
    //3x5 array/matrix
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 5; ++j) {
            printf("%d\t", grid[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 5; ++j) {
            printf("%c\t", xrid[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        printf("\n");
        for (int j = 0; j < 3; ++j) {
            printf("%s\t", srid[i][j]);
        }
    }

    printf("\n--------char[] vs *string------------\n");
    int i = 0;
    do {
//        printf("%s", charArray2[i]);   not works. it is a char array, not a string array
        printf("%c", charArray2[i]);
        i++;
    } while (charArray2[i] != '\0');

    printf("\n--------*string[] vs **string------------\n");
    i = 0;
    do {
        printf("%s \t", stringArray[i]);
        i++;
    } while (i < 4);

    //todo: add more elements to *string[]

    printf("\n--------*string[] vs **string------------\n");

    return 0;
}

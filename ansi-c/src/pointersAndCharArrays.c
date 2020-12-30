#include <stdio.h>

//gcc -o out/pointersAndCharArrays src/pointersAndCharArrays.c  && out/pointersAndCharArrays
int main(int argc, char const *argv[])
{
    //minor diff is the memory address value. hexOfPointer=valueOfHex
    char string1[] = "Hello";      //hexOfPointer=variableNameOfHex
    char *string2 = "Hello";       //pointing addr, of string pointer, in reality

    printf("hexOfPointer  |variableNameOfHex| value\n");
    printf("%x      |%x        | %s\n", &string1, string1, string1);
    printf("%x      |%x         | %s\n", &string2, string2, string2);

//    hexOfPointer  |variableNameOfHex| value
//    e7a3b6ba      |e7a3b6ba        | Hello
//    e7a3b6b0      |81c7f52         | Hello

// string2 = string1; is the same result. Because, string1 is the actual address!
    string2 = &string1;
    printf("hexOfPointer  |variableNameOfHex| value\n");
    printf("%x      |%x        | %s\n", &string1, string1, string1);
    printf("%x      |%x        | %s\n", &string2, string2, string2);

//    hexOfPointer  |variableNameOfHex| value
//    eb0016ba      |eb0016ba        | Hello
//    eb0016b0      |eb0016ba        | Hello

    return 0;
}
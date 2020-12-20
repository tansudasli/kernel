#include <stdio.h>
#include <stdlib.h>

//gcc -o out/userInput src/userInput.c  && out/userInput 
int main(int argc, char const *argv[])
{
    char iString[10];
    int i;


    //get something from user, unsafe, and cast it to a int
    printf("Enter a number:"); gets(iString);
    i = atoi(iString);

    printf("%d", i);

    //todo: add argv

    return 0;
}

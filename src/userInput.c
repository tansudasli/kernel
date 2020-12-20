#include <stdio.h>
#include <stdlib.h>

//gcc -o out/userInput src/userInput.c  && out/userInput 
//gcc -o out/userInput src/userInput.c  && out/userInput 12 
int main(int argc, char const *argv[])
{
    char iString[10];
    int i;


    //get something from user, unsafe and definitly string!!, and cast it to a int
    printf("Enter a number:"); 

    gets(iString);
    i = atoi(iString);  //if gets non integer, returns 0. So if it is 0, give error message
    i == 0 ? printf("Enter numeric value \n") : printf("%d \n", i);


    // get param from command line 
    for (int j = 1; j < argc; j++)
    {
        /* code */
        i = atoi(argv[j]);
        i == 0 ? printf("Enter numeric value \n") : printf("%d \n", i);
    }

    return 0;
}

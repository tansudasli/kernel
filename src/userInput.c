#include <stdio.h>
#include <stdlib.h>


void usingCommandLineParameters(int argc, char const *argv[]) {
    int i;

    // get param from command line 
    for (int j = 1; j < argc; j++)
    {
        /* code */
        i = atoi(argv[j]);
        i == 0 ? printf("Enter numeric value \n") : printf("Got from commandline= %d \n", i);
    }
}

void usingGetAndCasting() {
    char iString[5];
    int i;

    //get something from user, unsafe and definitly string!!, and cast it to a int
    printf("Enter a number: "); 

    gets(iString);
    i = atoi(iString);  //if gets non integer, returns 0. So if it is 0, give error message
    i == 0 ? printf("Enter numeric value \n") : printf("Got from screen= %d \n", i);
}

//gcc -o out/userInput src/userInput.c  && out/userInput 
//gcc -o out/userInput src/userInput.c  && out/userInput 12 
int main(int argc, char const *argv[])
{

    usingGetAndCasting();
    usingCommandLineParameters(argc, argv);


    return 0;
}

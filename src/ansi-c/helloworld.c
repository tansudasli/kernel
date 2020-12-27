#include <stdio.h>


// build & run with, 
//     gcc -o out/helloworld src/helloworld.c 
//     ./out/helloworld ali veli deli

//char **argv == char *argv[]
int main(int argc, char const *argv[])
{
    /* code */
    printf("hello World\n");
    puts("hi, again");

    //access 2 parameters
    for (size_t i = 0; i < argc; i++)
    {
        /* code */
        printf("%zu, argc=%d, %s \n", i, argc, argv[i]);
    }
    
    return 0;
}

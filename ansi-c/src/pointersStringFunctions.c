#include <stdio.h>
#include <string.h>
#include <mm_malloc.h>

#define MAXLENGTH 100


// we can not reassign like (message = message + name; ) to a char[], or any string :)
// also, we cannot reassign a char[].
char* stringOpsWithCharArray(char name[]) {
    char message[MAXLENGTH] = "Hi, ";

    strcat(message, name);

    return message;
}

//char*, we need to malloc to use strcat()
char* stringOpsWithCharPointer(char *name) {
    char *r = malloc(MAXLENGTH);

    strcat(r, "Hi, ");
    strcat(r, name);

    return r;
}

//gcc -o out/pointersStringFunctions src/pointersStringFunctions.c  && out/pointersStringFunctions
int main(int argc, char const *argv[]) {

    printf("%s\n", stringOpsWithCharArray("Ali"));
    printf("%s\n", stringOpsWithCharPointer("Veli"));

    return 0;
}

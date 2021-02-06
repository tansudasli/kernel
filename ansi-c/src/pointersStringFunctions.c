#include <stdio.h>
#include <string.h>
#include <mm_malloc.h>

#define MAXLENGTH 100


// we can not reassign like (message = message + name; ) to a char[], or any string :)
// also, we cannot reassign a char[].
char * stringOpsWithCharArray(char name[]) {
    char m[MAXLENGTH] = "Hi, "; //native or mandatory initialization

    return strcat(m, name);

//    return m;  m is local var and is created at stack. so creates warning
}

//char*, we need to malloc to use strcat()
char * stringOpsWithCharPointer(char * name) {
    char *r = malloc(MAXLENGTH);  //we had to initialize.
                                  //it is created at heap. so return r; is valid.
    //r[0] = '\0';    //do we really need this?

    strcat(r, "Hi, ");
    strcat(r, name);

    return r;
}

//only possible with char**.
void stringOpsWithParameter(char **name) {
    char *r = malloc(MAXLENGTH);

    strcat(r, *name);
    strcat(r, "Tansu");

    *name = r;  //changes message variable value.

    free(r);
}


//only possible with char**.
void stringOpsWithParameter(char **name) {
    char *r = malloc(MAXLENGTH);

    strcat(r, *name);
    strcat(r, "Tansu");

    *name = r;  //changes message variable value.

    free(r);
}


//gcc -o out/pointersStringFunctions src/pointersStringFunctions.c  && out/pointersStringFunctions
//gcc -o out/pointersStringFunctions src/pointersStringFunctions.c  && out/pointersStringFunctions abidindenyo
int main(int argc, char *argv[]) {

    //get by returning the new message
    printf("%s\n", stringOpsWithCharArray( "Ali"));
    printf("%s\n", stringOpsWithCharPointer(argc > 1 ? argv[1] : "Veli"));

    //change the message in place
    char *message = "Hi, ";
    stringOpsWithParameter( &message);
    printf("%s\n", message);


    return 0;
}

#include <stdio.h>
#include "header/readln.h"

//override if you want.
// #define STRLEN 10

int main(int argc, char const *argv[])
{
    /* code */
	char m[STRLEN];
    int result = readln(m, STRLEN);

    printf("lengthOfInput=%d, truncuatedInput=%s", STRLEN, m);
    
    return 0;
}
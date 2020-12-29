#include <stdio.h>
#include "header/readln.h"

//todo: override if you want.
//#define STRLEN 10

int main(int argc, char const *argv[])
{
    /* code */
	char m[STRLEN];

	readln(m, STRLEN);
	printf("lengthOfInput=%d, truncatedInput=%s", STRLEN, m);
    
    return 0;
}
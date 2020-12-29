#include <stdio.h>
#include "../header/readln.h"


//gcc -o out/readChar src/test/readChar.c  && out/readChar
int main(int argc, char const *argv[])
{
    char name[STRLEN];

    /* code */
    readChar(name, STRLEN);
    printf("truncated (maxLen=%d, truncatedString=%s)", STRLEN, name);

    return 0;
}

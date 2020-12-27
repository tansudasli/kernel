#include <stdio.h>
#include "../header/readln.h"


//gcc -o out/readChar src/test/readChar.c  && out/readChar
int main(int argc, char const *argv[])
{
    char name[STRLEN];

    /* code */
    int result = readChar(name, STRLEN);
    printf("trancuated (maxLen=%d, trancuatedString=%s)", STRLEN > result ? STRLEN-1 : result, name);

    return 0;
}

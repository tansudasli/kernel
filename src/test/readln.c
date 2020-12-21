#include <stdio.h>

//gcc -o out/readln src/test/readln.c  && out/readln
int main(int argc, char const *argv[])
{
    /* code */
    char string[5];

    printf("Enter a char: ");
    int ch = getchar();   //reads and returns numeric value of char,  97 for a

    //in a normal scenario, use for and increment string value makes it a word!
    string[0] = ch;       //sets as char, a

    printf("ch=%d, %s", ch, string);

    return 0;
}

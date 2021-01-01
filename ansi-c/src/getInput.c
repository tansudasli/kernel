#include <stdio.h>
#include "header/interaction.h"


//gcc src/getInput.c src/utility/interaction.c -o out/getInput  && out/getInput
int main(int argc, char const *argv[])
{
    /* code */
	char m[STRLEN];

	printf("Enter a string: ");

//	readLn(m, STRLEN);
	readChar(m, STRLEN);  //more accurate

	printf("lengthOfInput=%d, maxLength=%d => truncatedInput=%s", STRLEN, STRLEN, m);
    
    return 0;
}
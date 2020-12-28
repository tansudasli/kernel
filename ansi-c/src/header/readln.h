#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STRLEN 5

/**
 * to read more accurate and robust from user (via stdin)
 */ 
int readln(char s[], int maxlen) {
	int len_s;
	fgets(s, maxlen, stdin);
	len_s = strlen(s);
	// if (s[len_s - 1] == '\n') {
	// 	s[len_s - 1] = '\0';
	// 	len_s -= 1;
	// }
	rewind(stdin); // This flushes the keyboard buffer (on Windows anyway!)
	return len_s;
}

/**
 * to read accurate and robust from user (via stdin)
 */
int readChar(char s[], int maxlen) {
	char ch;
	int len_s;
    bool remainingChars = true;
	
	int counter = 0;
	while (remainingChars) {
		ch = getchar();

		if ((ch == '\n') || (ch == EOF)) {
			remainingChars = false;
		} 
		else if (counter < maxlen)
		{
			//go on building string
			s[counter] = ch;
			counter++;
		}
	}
    s[counter] = '\0';
	return counter;
}
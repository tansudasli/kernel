#include <stdio.h>
#include <string.h>

#define STRLEN 5

/**
 * to read more accurate and robust read from user (via stdin)
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

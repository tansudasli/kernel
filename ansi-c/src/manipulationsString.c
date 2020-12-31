#include <stdio.h>
#include <string.h> 

#define MAX_STRING_LENGTH 200

//    char *string;
char sentence[] = "On the dark night, Fallow the light and Embrace the shadow which will lead you the way.";
char tens[]     = "        10        20        30        40        50        60   65";
char nums[]     = "123456789012345678901234567890123456789012345678901234567890123456";

void printString() {
    printf("%s\n%s \n%s", sentence, tens, nums);
}

void searchString(char source[], char searchString[]) {

    char *foundAt = strstr(source, searchString);
    int index = (int)(foundAt - source);

    foundAt != NULL ? printf("%s, %d ... %d => %d\n", foundAt, source, foundAt, index) : printf("Not found");

}

// gcc -o out/manipulationsString src/manipulationsString.c  && out/manipulationsString
int main(int argc, char const *argv[]) {

    printf("%lu \t%lu\n", strlen(sentence), strlen(tens));

    printString(); printf("\n");

    printf("%c\n", sentence[65]);
    searchString(sentence, "will");

    printf("%c\n", sentence[12]);
    searchString(sentence, "night");

    return 0;
}

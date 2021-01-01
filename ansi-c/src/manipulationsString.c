#include <stdio.h>
#include <string.h> 

#define MAX_STRING_LENGTH 200

//    char *string;
char sentence[] = "On the dark night, Fallow the light and Embrace the shadow which will lead you the way.";
char tens[]     = "        10        20        30        40        50        60   65";
char nums[]     = "123456789012345678901234567890123456789012345678901234567890123456";


/**
 * Returns index (zero based). If not found, return -1
 *
 * @param source
 * @param searchString
 * @return -1 or index
 */
int searchString(char source[], char searchString[]) {

    char *foundAt = strstr(source, searchString);
    int index = (int)(foundAt - source);

    if (foundAt == NULL)
        index = -1;

    return index;
}

// gcc -o out/manipulationsString src/manipulationsString.c  && out/manipulationsString
int main(int argc, char const *argv[]) {

    printf("%lu \t%lu\n", strlen(sentence), strlen(tens));

    //print string and indexes
    printf("%s\n%s \n%s\n", sentence, tens, nums);

    //or calculate pointer addr. => sentence + searchString(sentence, "night")
    printf("%s\n", &sentence[searchString(sentence, "night")]);
    printf("%s\n", &sentence[searchString(sentence, "will")]);


    return 0;
}

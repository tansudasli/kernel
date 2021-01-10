#include <stdio.h>

#define SIZE 3

char *words[SIZE];   //hold some initial data  w0 w1 w2  => char[][]

void initialize() {
    words[0] = "ali";
    words[1] = "veli";
    words[2] = "deli";

    for (int j = 0; j < SIZE; j++)
        printf("%s\t", words[j]);
}

int main(int argc, char **argv) {

    char ch = 'c';   //value
    char *pc;        //pointer                 char pc[]                  or  a word (n length but still 1 word)
    char **ppc;      //pointer to pointer      char *pc[] or  char pc[][] or  a kind of word list

    initialize();

    return 0;
}
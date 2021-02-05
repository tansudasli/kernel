#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/Stack.h"


#define ROW 3

int main (int argc, char **argv) {

    //test data
    char * word[ROW] = {"abidindenyo",
                        "kazablankalastiramadiklarimizdan misiniz?",
                        ">>olalo<<"
                       };

    //check lengths
    printf("%lu  %lu\n", strlen(word[0]),
                         strlen(word[1]));

    for (int j = 0; j < ROW; j++) {

        //print original char by char
        printf("%s ", word[j]);

        //reverse
        size_t len = strlen(word[j]);
        DATA ch;
        for (int i = 0; i < len; i++) {
            ch.info = (int)*word[j]++;
            push(ch);
        }

        while (top)
            printf("%c", (char) pop()->data.info);

        printf("\n");
    }




    return 0;
}
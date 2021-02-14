#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/Stack.h"

#define ROW 3

int main (int argc, char **argv) {

    //test data
    char * word[ROW] = {"abidindenyo", "kazablankalastiramadiklarimizdan misiniz?", ">>olalo<<"};

    //check lengths
    printf("%lu  %lu\n", strlen(word[0]),
                         strlen(word[1]));

    for (int j = 0; j < ROW; j++) {

        //print original char by char
        printf("%s ", word[j]);

        //reverse
        DATA ch;
        int length = strlen(word[j]);
        ch.info = (int)*word[j]++;

        //init
        NODE *stack = create(ch);

        for (int i = 1; i < length; i++) {
            ch.info = (int)*word[j]++;
            push(&stack, ch);
        }

        while (!isEmpty(&stack)) {
            NODE *n = pop(&stack);

            printf("%c", (char) n->data.info);

            free(n);
        }

        printf("\n");
    }

    return 0;
}
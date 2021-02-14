#include <stdio.h>
#include <stdlib.h>

#include "header/Stack.h"


int main (int argc, char **argv) {
    /**
     * creating 2 independent stacks at the same time
     */

    //preparations
    DATA numbers[] = {5, 8, 10, 20, 31, 57, 45, 73, 32, 31, 3, 7, 9, 99};
    DATA symbols[] = {'(', '[', '{', '}', ']', ')'};

    int lS = sizeof(symbols) / sizeof(symbols[0]);
    int lN = sizeof(numbers) / sizeof(numbers[0]);

    printf("\n---------------1---------------\n");

    //print original
    printf("pushed.. ");
    for (int i = 0; i < lS; i++)
        printf("%c  ", (char) symbols[i].info);

    //create 1st stackSymbols
    NODE *stackSymbols = create(symbols[0]);

    //push
    for (int i = 1; i < lS; i++)
        push(&stackSymbols, symbols[i]);

//    printf("-->%d", isEmpty(&stackSymbols));

    //pop
    NODE *t;
    printf("\npopped.. ");
    for (int i = 0; i < lS; i++) {
        t = pop(&stackSymbols);

        printf("%c  ", (char) t->data.info);
        free(t);
    }

//    printf("-->%d", isEmpty(&stackSymbols));

    printf("\n---------------2---------------\n");

    //simulate second stack at sametime!!
    printf("pushed.. ");
    for (int i = 0; i < lN; i++)
        printf("%d  ", numbers[i].info);

    //create 1st stackSymbols
    NODE *stackNumbers = create(numbers[0]);

    //push
    for (int i = 1; i < lN; i++)
        push(&stackNumbers, numbers[i]);

    //pop
    NODE *k;
    printf("\npopped.. ");
    for (int i = 0; i < lN; i++) {
        k = pop(&stackNumbers);

        printf("%d  ", k->data.info);
        free(k);
    }

    //free


    return 0;
}
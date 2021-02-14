#include <stdio.h>
#include <stdlib.h>

#include "header/Stack.h"


#define COLUMN 6
#define ROW 3

int main (int argc, char **argv) {

    //test data
    DATA k[ROW][COLUMN] = {{'(', '[', '{', '}', ']', ')'},
                           {'(', '[', '{', '}', '[', ')'},
                           {'{', '[', '(', ')', '[', '}'}
                          };

    for (int j = 0; j < ROW; j++) {

        //print original
        for (int i = 0; i < COLUMN; i++)
            printf("%c  ", (char) k[j][i].info);

        //evaluate
        bool r = true;
        NODE *stack = create(k[j][0]);
        for (int i = 1; i < COLUMN; i++) {

            //then, pop and compare
            DATA c = k[j][i];

            //if an open bracket, push to the stack
            if (c.info == '{' || c.info == '(' || c.info == '[') {
                push(&stack, c);

                continue;
            }

            //if not an open bracket, then we should look for closed brackets, and compare
            NODE *n = pop(&stack);
            if (!n) {
                perror("error getting node");
                break;
            };

            switch (c.info) {
                case '}':  if (n->data.info == '{') {free(n); continue;}
                case ']':  if (n->data.info == '[') {free(n); continue;}
                case ')':  if (n->data.info == '(') {free(n); continue;}

                default: r = false; break;
            }

            free(n);

            break;
        }

        r ? printf(" ->balanced") : printf(" ->Unbalanced");

        printf("\n");
    }

    return 0;
}
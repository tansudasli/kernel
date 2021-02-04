#include <stdio.h>
#include <stdlib.h>

#include "header/Stack.h"


bool isBalanced(DATA c) {
    NODE *p = NULL;

    //if an open bracket, push to the stack
    if (c.info == '{' || c.info == '(' || c.info == '[') {
        push(c);
        return true;
    }

    //if not an open bracket, then we should look for closed brackets, and compare
    p = pop();
    if (!p) return false;

    switch (c.info) {
        case '}':  if (p->data.info == '{') return true;
        case ']':  if (p->data.info == '[') return true;
        case ')':  if (p->data.info == '(') return true;

        default: return false;
    }
}

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
        //1st, push
        bool r = true;
        for (int i = 0; i < COLUMN; i++) {

            //then, pop and compare
            r = isBalanced(k[j][i]);
            if (r) continue;

            break;
        }

        r ? printf(" ->balanced") : printf(" ->Unbalanced");

        printf("\n");
    }




    return 0;
}
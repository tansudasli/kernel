#include <stdio.h>
#include <stdlib.h>

#include "header/Stack.h"


int main (int argc, char **argv) {

    //add to last
    //creates sorted intentionally!
    DATA n[] = {'(', '[', '{', '}', ']', ')'}; int l = 6;
//    DATA n[] = {'(', '[', '{', '}', '[', ')'}; int l = 6;


    //print original
    printf("------------original------------\n");
    for (int i = 0; i < l; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");

    //push
    NODE *p = NULL;
    bool isBalanced = true;
    for (int i = 0; i < l; i++) {

        //open brackets
        if (n[i].info == '{' || n[i].info == '(' || n[i].info == '[') {
            push(n[i]);
            continue;
        }

        //now, we should look for closed brackets
        p = pop();
        if (!p) break;

        //todo: switch is more elegant
        if (n[i].info == '}' && p->data.info == '{')
            continue;
        else if (n[i].info == ']' && p->data.info == '[')
            continue;
        if (n[i].info == ')' && p->data.info == '(')
            continue;
        else {
            isBalanced = false;
            break;
        }
    }

    isBalanced ? printf("balanced") : printf("not balanced");


    printf("\n------------------------------\n");

    return 0;
}
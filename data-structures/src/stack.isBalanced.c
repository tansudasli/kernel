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

        //if an open bracket, push to the stack
        if (n[i].info == '{' || n[i].info == '(' || n[i].info == '[') {
            push(n[i]);
            continue;
        }

        //if not an open bracket, then we should look for closed brackets, and compare
        p = pop();
        if (!p) break;

        switch (n[i].info) {
            case '}':  if (p->data.info == '{') continue;
            case ']':  if (p->data.info == '[') continue;
            case ')':  if (p->data.info == '(') continue;

            default: isBalanced = false; break;
        }

    }

    isBalanced ? printf("balanced") : printf("not balanced");

    printf("\n------------------------------\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "header/Stack.h"

NODE *p = NULL;

int main (int argc, char **argv) {

    //add to last
    //creates sorted intentionally!
//    DATA n[] = {5, 8, 10, 20, 31, 57};
    DATA n[] = {'(', '[', '{', '}', ']', ')'};
    int l = sizeof(n)/sizeof(n[0]);

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < l; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");

    //push
    for (int i = 0; i < l; i++)
        push(n[i]);

    printf("isEmpty after push() all= %s\n", isEmpty() ? "true" : "false");

    //pop & print
    NODE *t;
    for (int i = 0; i < l; i++) {
        t = pop();

        printf("%d  ", t->data.info);
    }

    printf("\nisEmpty after pop() all= %s",  isEmpty() ? "true" : "false");
    printf("\n------------------------------\n");



    return 0;
}
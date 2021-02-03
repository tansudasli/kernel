#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/Stack.h"

void push(DATA d) {

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init rest
    p->link = !top ? NULL : top;
    p->data.info = d.info;

    //inject
    top = p;
}

NODE * pop() {
    //get top, adjust and return
    if (!top) {
        perror("stackoverflow");
        return NULL;
    }

    // get top
    NODE *p = top;

    //inject
    top = top->link;

    return p;
}

NODE * peek() {

    return top;
}

bool isEmpty() {
    
   return !top ? true : false;
}
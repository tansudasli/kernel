#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/Stack.h"

/**
 * If top is Null, then creates 1st node and pushes. Otherwise, pushes just as top.<br>
 * No need to use init(), or create(). Very lightweight and simple.<br>
 *
 * @param d: DATA new node
 */
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

/**
 * Gets last in node, then updates the remaining as top.
 *
 * @return : top node
 */
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

/**
 * Get last in node, but do not update top. Good for checking, comparing etc..<br>
 * 
 * @return : top node
 */
NODE * peek() {

    return top;
}

/**
 * Check stack has nodes or not.<br>
 *
 * @return true, if empty or otherwise false.
 */
bool isEmpty() {
    
   return !top ? true : false;
}
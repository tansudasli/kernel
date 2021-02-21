#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/Stack.h"


/**
 * Initializes and creates 1st node of Stack. This becomes the top node.
 *
 * @param d : top node's Data
 * @return : top node which points to (1st node)
 */
NODE * create(DATA d) {

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return NULL;
    }

    //init rest
    p->link = NULL;
    p->data.info = d.info;

    return p;

}

 /**
  *  It pushes new node as the new top. And adjust old top.<br>
  *  Use create() before pushing first, then push().
  *
  * @param top : Address of old top node is updated as new top. if it is NULL, not-created error occurs.
  * @param d : DATA new node
  */
void push(NODE **top, DATA d) {

    if (!top) {
        perror("not-created");
        return;
    }

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init rest
    p->link = *top;
    p->data.info = d.info;

    //inject
    *top = p;
}

/**
 * Gets top node (t), then updates next node as the new top, and returns old top node.
 *
 * @param top : Address of old top node provided by client that is updated as new top. if it is NULL, stack-overflow error occurs.
 * @return : old top node (which is also given as t)
 */
NODE * pop(NODE **top) {

    if (!top) {
        perror("stack-overflow");
        return NULL;
    }

    // get top
    NODE *p = *top;

    //inject
    *top = p->link;

    return p;
}

/**
 * Gets top node (top), but does not do any update in stack. Good for checking, comparing etc..<br>
 *
 * @param top: top node by client
 * @return : top itself.
 */
NODE * peek(NODE **top) {

    return *top;
}

/**
 * Check stack has nodes or not.<br>
 *
 * @return true, if empty or otherwise false.
 */
bool isEmpty(NODE **top) {
    
   return !*top ? true : false;
}
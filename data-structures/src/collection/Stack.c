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
  * @param t : Address of old top node is updated as new top. if it is NULL, not-created error occurs.
  * @param d : DATA new node
  */
void push(NODE **t, DATA d) {

    if (!t) {
        perror("not-created");
        return;
    }

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init rest
    p->link = *t;
    p->data.info = d.info;

    //inject
    *t = p;
}

/**
 * Gets top node (t), then updates next node as the new top, and returns old top node.
 *
 * @param t : Address of old top node provided by client that is updated as new top. if it is NULL, stack-overflow error occurs.
 * @return : old top node (which is also given as t)
 */
NODE * pop(NODE **t) {

    if (!t) {
        perror("stack-overflow");
        return NULL;
    }

    // get top
    NODE *p = *t;

    //inject
    *t = p->link;

    return p;
}

/**
 * Gets top node (t), but does not do any update in stack. Good for checking, comparing etc..<br>
 *
 * @param t: top node by client
 * @return : t itself.
 */
NODE * peek(NODE **t) {

    return *t;
}

/**
 * Check stack has nodes or not.<br>
 *
 * @return true, if empty or otherwise false.
 */
bool isEmpty(NODE **t) {
    
   return !*t ? true : false;
}
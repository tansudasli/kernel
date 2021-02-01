#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/ArrayList.h"


/**
 * Inits variables
 */
static void init() {
    start = NULL;
    last = NULL;

    nodeCount = 0;
    sorted = false;
}

/**
 * Initializes and creates empty ArrayList.
 *
 * @return start node
 */
NODE * create() {

    init();

    start = (NODE *) calloc(1, sizeof(NODE));
    if (!start) {
        perror("no-allocation");
        return NULL;
    }

    //init rest
    start->next = NULL;
    start->previous = NULL;
    start->data.info = -1;

    //inject
    last = start;

    return start;
}

/**
 * Appends to the last.
 * After create(), always use append() for the first node. Then use attach() or insert().
 * If,
 *   - start is NULL, error occurs
 *   - otherwise,
 *       - if empty, appends to start.
 *       - or, appends to last
 *
 * @param d: DATA to append
 */
void append(DATA d) {
    if (!start) {
        perror("not created");
        return;
    }

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init new node
    p->data = d;
    p->next = NULL;
    p->previous = last;

    //append
    last->next = p;

    //injections
    last = p;
    nodeCount++;
}

/**
 * Inserts between start and first node.
 * If,
 *   - start is NULL or empty, error occurs
 *   - otherwise, appends to the last.
 *
 * @param d : DATA to attach
 */
void attach(DATA d) {
    if (!start) {
        perror("not created");
        return;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return;
    }

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init new node
    p->data = d;
    p->next = start->next;
    p->previous = start;
    start->next->previous = p;

    //attach
    start->next = p;

    //injections
    nodeCount++;

}

/**
 * Insert between first and last nodes.
 * If,
 *   - start is NULL or empty, error occurs
 *   - s is start, then inserting BEFORE triggers attach()
 *   - s is last, then inserting AFTER triggers append()
 *   - otherwise, search() s, then inserts regarding pos.
 *
 * @param s: DATA to find
 * @param pos: BEFORE or AFTER position to insert
 * @param d: DATA to insert
 */
void insert(DATA s, POSITION pos, DATA d) {
    if (!start) {
        perror("not created");
        return;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return;
    }

    //search
    NODE *p = search(s);
    if (!p) {
        perror("not found");
        return;
    }

    //p is first node (after start), so inserting before means attaching!
    if (p == start->next && pos == BEFORE) {
        printf("...trigger attach()");
        attach(d);

        return;
    }
    //p is last node, so inserting after means appending!
    if (p == last && pos == AFTER) {
        printf("...trigger append()");
        append(d);

        return;
    }

    //init
    NODE *tmp = (NODE *) calloc(1, sizeof(NODE));
    if(!tmp) {
        perror("no-allocation");
        return;
    }

    //insert: between which means no touch to start or last
    if (pos == BEFORE) {

        tmp->data = d;
        tmp->next = p;
        tmp->previous = p->previous;
        p->previous->next = tmp;
        p->previous = tmp;

        //injections
        nodeCount++;

    } else {

        tmp->data = d;
        tmp->next = p->next;
        tmp->previous = p;
        p->next->previous = tmp;
        p->next = tmp;

        //injections
        nodeCount++;
    }

}

/**
 * Delete a node
 * If,<br>
 *    s is 1st node, delete 1st, adjust start<br>
 *    s is 1st and only node, delete and free()<br>
 *    s is last, delete last<br>
 *    s is between 1st and last, delete<br>
 *    s is not found, error<br>
 *
 * @param s : DATA to search and delete
 * @return : if error or not found, return -1 or return 0
 */
int delete(DATA s) {
   //

   return 0;
}

/**
 * Insert between first and last nodes.
 * If,
 *   - start is NULL or empty, error occurs
 *   - otherwise, loops all nodes till found
 *
 * @param s : DATA to search in nodes
 * @return : found node or NULL if not found or error occurred.
 */
NODE * search(DATA s) {
    if (!start) {
        perror("not created");
        return NULL;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return NULL;
    }

    //loop all
    NODE *p = start;
    do {
        if (p->data.info == s.info)
            break;

        p = p->next;
    } while (p);

    return p;
}

NODE * binarySearch(DATA s) {
    if (!start) {
        perror("not created");
        return NULL;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return NULL;
    }

    NODE *b, *e, *m;
    do {
//        m =
    } while ( 1==1);

    //find middle node
    //compare middle, then divide again, till it found
}

/**
 * Start node
 *
 * @return : start
 */
NODE * getFirst() {

    return start;
}

/**
 * Last node
 *
 * @return : last
 */
NODE * getLast() {

    return last;
}

NODE * getMiddle(NODE *b, NODE *e) {
    //if count is even (count/2)+1, otherwise (count/2)
    NODE *slow = start, *fast = start;

    do {
        slow = slow->next;
        fast = fast->next->next;

    } while (fast != last || !fast);

    return slow;
}

/**
 * Node count
 * - except start node
 *
 * @return : node count
 */
int size() {

    return nodeCount;
}

/**
 * Default not sorted.
 *
 * @return : bool
 */
bool isSorted() {
    return sorted;
}

/**
 * some internal stats , pointer's addr etc...
 */
void stats() {

    if (!start) {
        perror("not created");
        return;
    }

    printf("\n\n---------------stats----------------\n");

    NODE *p = start;
    printf("seq data prev\t\t p\t\t next\n");
    int i = 0;
    do {
        printf("%d   %d\t %p\t %p\t %p\n", i, p->data.info, p->previous, p, p->next);

        i++;
        p = p->next;
    } while (p);

    printf("------------end of stats------------\n");

}

/**
 * Prints
 */
void display() {

    if (!start) {
        perror("not created");
        return;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return;
    }

    NODE *p = start;
    do {
        printf("%d  ", p->data.info);

        p = p->next;
    } while (p);

}

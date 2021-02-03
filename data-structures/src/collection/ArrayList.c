#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/ArrayList.h"


/**
 * Inits variables
 */
static void init() {
    head = NULL;
    tail = NULL;

    nodeCount = 0;
    sorted = false;
}

/**
 * Initializes and creates 1st node of ArrayList.
 * Sets Tail and Head pointers to the 1st node.
 *
 * @param d : 1st node's Data
 * @return : head node which points to (1st node)
 */
NODE * create(DATA d) {

    init();

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return NULL;
    }

    //init rest
    p->next = NULL;
    p->previous = NULL;
    p->data.info = d.info;

    //inject
    head = p;
    tail = head;
    nodeCount++;

    return head;
}

/**
 * Appends to the last.
 *
 * If,
 *   - head is NULL, error occurs
 *   - otherwise, appends to tail
 *
 * @param d: DATA to append
 */
void append(DATA d) {
    if (!head) {
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
    p->previous = tail;

    //append
    tail->next = p;

    //injections
    tail = p;
    nodeCount++;
}

/**
 * Inserts between 1st and 2nd node.
 * If,
 *   - head is NULL or (size = 0), error occurs
 *   - otherwise, inserts  to the last.
 *
 * @param d : DATA to attach
 */
void attach(DATA d) {
    if (!head) {
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
    p->next = head;
    p->previous = NULL;
    head->previous = p;

    //attach
    head = p;

    //injections
    nodeCount++;
}

/**
 * Insert between head and tail nodes.
 * If,
 *   - head is NULL or (size = 0), error occurs
 *   - s is head, then inserting BEFORE triggers attach()
 *   - s is tail, then inserting AFTER triggers append()
 *   - otherwise, search() s, then inserts regarding pos (BEFORE or AFTER).
 *
 * @param s: DATA to find
 * @param pos: BEFORE or AFTER position to insert
 * @param d: DATA to insert
 */
void insert(DATA s, POSITION pos, DATA d) {
    if (!head) {
        perror("not created");
        return;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return;
    }

    //search
    //todo: uses search() instead of binarySearch(). optimize
    NODE *p = search(s);
    if (!p) {
        perror("not found");
        return;
    }

    //p is first node, so inserting before means attaching!
    if (p == head && pos == BEFORE) {
        printf("...trigger attach()");
        attach(d);

        return;
    }
    //p is last node, so inserting after means appending!
    if (p == tail && pos == AFTER) {
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

    //insert: between which means no touch to head or tail nodes
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
 * Insert as sorted.
 *
 * @param d : DATA to insert
 */
void insertSorted(DATA d) {
    if (!head) {
        perror("not created");
        return;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return;
    }

    //if head is valid, means i have a node.

    //init new node
    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    p->data = d;


    // <, 1st node comparison
    NODE *cursor = head;
    if (p->data.info <= cursor->data.info) {
        attach(d);

        sorted = true;
        return;
    }

    // > then 1st node, but we should find appropriate place
    cursor = cursor->next;
    do {

        // > then head, so compare with next node,
        // so, we should use < operator, to find the node that is right before max
        if (p->data.info < cursor->data.info) {
            //insert before!
            p->next = cursor;
            p->previous = cursor->previous;
            cursor->previous->next = p;
            cursor->previous = p;

            //injections
            nodeCount++;
            sorted = true;

            break;
        }

        cursor = cursor->next;
    } while (cursor);

    // at the end of list, and cursor is null, means we have max node.
    if (!cursor) {
        append(d);

        sorted = true;
    }

}

/**
 * Delete a node
 * If,<br>
 *    s is 1st node, delete 1st, adjust head<br>
 *    s is 1st and only node, delete and free()<br>
 *    s is last, delete last, adjust tail <br>
 *    s is between 1st and last, delete<br>
 *    s is not found, error<br>
 *
 * @param s : DATA to search and delete
 * @return : if error or not found, return -1 or return 0
 */
int delete(DATA s) {
   //search vs binarySearch

   //delete

   //injections

   return 0;
}

/**
 * Searches from 1st to last nodes.
 * If,
 *   - start is NULL or (size = 0), error occurs
 *   - otherwise, loops all nodes till it founds
 *
 * @param s : DATA to search in nodes
 * @return : founded node, otherwise NULL if not found or error occurred.
 */
NODE * search(DATA s) {
    if (!head) {
        perror("not created");
        return NULL;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return NULL;
    }

    //loop all
    NODE *p = head;
    do {
        if (p->data.info == s.info)
            break;

        p = p->next;
    } while (p);

    return p;
}

/**
 * Finds middle node and then, makes comparison.
 * Focuses always middle, and compares with middle. At last steps, either b or e will be null, or b > e.
 * So there are 4 possible exit ways!!
 * Works on sorted data.
 *
 * @param s : search data
 * @return : if not found NULL, otherwise matching node
 */
NODE * binarySearch(DATA s) {
    if (!head) {
        perror("not created");
        return NULL;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return NULL;
    }

    NODE *b = head, *e = tail, *m = NULL;
    do {
        //find middle
        m = getMiddle(b, e);
        if (!m) return NULL;

        //decide what to do
        if (s.info == m->data.info) return m;
        if (s.info > m->data.info) b = m->next;
        if (s.info < m->data.info) e = m->previous;

        //if, invalid, break
        if (b > e) break;

    } while (e); //todo: (e || b) ?

    return NULL;

    //compare middle, then divide again, till it found
}

/**
 * Start node
 *
 * @return : start
 */
NODE * getFirst() {

    return head;
}

/**
 * Last node
 *
 * @return : last
 */
NODE * getLast() {

    return tail;
}

/**
 * Locates middle node, using start end end node approach. So it can be called recursively.
 * Uses 2 pointers, one moves 1-step, second moves 2-steps. When faster reaches the end, slow shows the middle.
 * Better than mathematical (n/2) approach, if you can not have (or not meaningful) index-based reach.
 * Useful for binarySearch() method.
 *
 * @param b : beginning node
 * @param e : end node
 * @return : middle node
 */
NODE * getMiddle(NODE *b, NODE *e) {
    if (!b) {
        return NULL;
    }
    if (!e) {
        return NULL;
    }

    //
    NODE *slow = b, *fast = b;
    while (fast != e) {
        //moving fast 2-steps cause missing end point.
        if (fast->next == e) {
            slow = slow->next;
            break;
        }

        slow = slow->next;
        fast = fast->next->next;
    };

    return slow;
}

/**
 * Node count
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

    if (!head) {
        perror("not created");
        return;
    }

    printf("\n\n---------------stats----------------\n");

    NODE *p = head;
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

    if (!head) {
        perror("not created");
        return;
    }
    if (nodeCount == 0) {
        perror("not initialized");
        return;
    }

    NODE *p = head;
    do {
        printf("%d  ", p->data.info);

        p = p->next;
    } while (p);

}

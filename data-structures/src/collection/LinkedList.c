#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/LinkedList.h"


/**
 * Initializes and creates 1st node of ArrayList, sets head and returns head.
 * So client can use head in his code.
 * Sets Tail and Head pointers to the 1st node. To create as a sorted list set sorted=true.
 * <br><br>
 * @param d : DATA to attach as new head node
 * @param sorted : sorted list. default false.
 * @return : head node which points to (1st node)
 */
NODE * create(DATA d, bool sorted) {

    NODE *head = (NODE *) calloc(1, sizeof(NODE));
    if (!head) {
        perror("no-allocation");
        return NULL;
    }

    //init
    head->header.tail = NULL;
    head->header.nodeCount = 0;
    head->header.sorted = (sorted ? sorted : false);
    head->next = NULL;
    head->previous = NULL;

    //inject
    head->data.info = d.info;
    head->header.tail = head;
    head->header.nodeCount++;

    return head;
}

/**
 * Appends to the last node.<br>
 * Use insertSorted() method in a sorted list.
 * <br><br>
 * @param head : head node's addr. If, head is NULL, error occurs. Use create() first, to get a head
 * @param d : DATA to append as new node
 */
void append(NODE **head, DATA d) {
    if (!head) {
        perror("not created");
        return;
    }
//    insertSorted() calls attach() and append() methods automatically. Enabling this creates error.
//    if ((*head)->header.sorted) {
//        perror("invalid usage in a sorted list");
//        return;
//    }

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init new node
    p->data = d;
    p->next = NULL;
    p->previous = (*head)->header.tail;

    //append
    (*head)->header.tail->next = p;

    //injections
    (*head)->header.tail = p;
    (*head)->header.nodeCount++;
}

/**
 * Replaces 1st (head) node, and makes it second node. Sets new node as the head.<br>
 * Use insertSorted() method in a sorted list.
 * <br><br>
 * @param head : head node's addr. After replacement, it is updated as new head addr, and HEADER data copied to the new.
 *               If, head is NULL, error occurs. Use create() first, to get a head
 * @param d : DATA to attach as new node
 */
void attach(NODE **head, DATA d) {
    if (!head) {
        perror("not created");
        return;
    }
//    insertSorted() calls attach() and append() methods automatically. Enabling this creates error.
//    if ((*head)->header.sorted) {
//        perror("invalid usage in a sorted list");
//        return;
//    }

    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    if (!p) {
        perror("no-allocation");
        return;
    }

    //init new node
    p->data = d;
    p->next = *head;
    p->previous = NULL;
    (*head)->previous = p;

    //attach
    p->header.tail = (*head)->header.tail;
    p->header.nodeCount = (*head)->header.nodeCount;
    p->header.sorted = (*head)->header.sorted;
    *head = p;

    //injections
    (*head)->header.nodeCount++;
}

/**
 * Inserts between head and tail nodes.<br>
 * If,
 *   - s is head, then inserting BEFORE triggers attach(), and updates head in-place again.
 *   - s is tail, then inserting AFTER triggers append()
 *   - otherwise, searches s, then inserts regarding pos (BEFORE or AFTER).
 * <br><br>
 * @param head : head node's addr. If, head is NULL, error occurs. Use create() first, to get a head.
 *               If, It is sorted, error occurs, use insertSorted().
 * @param s : DATA to find node
 * @param d : DATA to insert as new node
 * @param pos : BEFORE or AFTER position to insert
 */
void insert(NODE **head, DATA s, DATA d, POSITION pos) {
    if (!head) {
        perror("not created");
        return;
    }
    if ((*head)->header.sorted) {
        perror("invalid usage in a sorted list");
        return;
    }

    //search
    //todo: uses search() instead of binarySearch(). optimize
    NODE *p = search(head, s);
    if (!p) {
        perror("not found");
        return;
    }

    //if p is the first node, so inserting before means attaching!
    if (p == *head && pos == BEFORE) {
        printf("...trigger attach()");
        attach(head, d);

        return;
    }

    //if p is the last node, so inserting after means appending!
    if (p == (*head)->header.tail && pos == AFTER) {
        printf("...trigger append()");
        append(head, d);

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
        (*head)->header.nodeCount++;

    } else {

        tmp->data = d;
        tmp->next = p->next;
        tmp->previous = p;
        p->next->previous = tmp;
        p->next = tmp;

        //injections
        (*head)->header.nodeCount++;
    }

}

/**
 * Inserts as sorted.
 * <br><br>
 * @param head : head node's addr. If, head is null, use create() as sorted true.
 * @param d : DATA to insert as new node
 */
void insertSorted(NODE **head, DATA d) {
    if (!head) {
        perror("not created");
        return;
    }
    if (!(*head)->header.sorted) {
        perror("invalid usage in an unsorted list");
        return;
    }

    //if head is valid, means i have a node.

    //init new node
    NODE *p = (NODE *) calloc(1, sizeof(NODE));
    p->data = d;

    // <, 1st node comparison
    NODE *cursor = *head;
    if (p->data.info < cursor->data.info) {     //comparison I

        attach(head, d);

        return;
    }

    // > then 1st node, but we should find appropriate place
    cursor = cursor->next;

    while (cursor) {

        // > then head, so compare with next node, so, we should use < operator, to find the node that is right
        if (p->data.info < cursor->data.info) {  //comparison II

            //insert before!
            p->next = cursor;
            p->previous = cursor->previous;
            cursor->previous->next = p;
            cursor->previous = p;

            //injections
            (*head)->header.nodeCount++;

            break;
        }

        cursor = cursor->next;
    };

    // at the end of list, and cursor is null (,or just after initialized), means we traversed all nodes.
    if (!cursor) {

        append(head, d);

    }

    return;
}

/**
 * Deletes node<br>
 * If,<br>
 *    s is 1st node, delete 1st, adjust head<br>
 *    s is 1st and only node, delete and free()<br>
 *    s is last, delete last, adjust tail <br>
 *    s is between 1st and last, delete<br>
 *    s is not found, error<br>
 * <br><br>
 * @param head : head node's addr.
 * @param s : DATA to search and to delete
 * @return : if error occurs, return -1 or return 0
 */
int delete(NODE **head, DATA s) {
   //search vs binarySearch

   //delete

   //injections

   return 0;
}

/**
 * Searches from head to tail node.
 * <br><br>
 * @param head, If head is NULL, error occurs
 * @param s : DATA to search in nodes
 * @return : if founds, returns the node, otherwise NULL.
 */
NODE * search(NODE **head, DATA s) {  //todo: compare function ?
    if (!head) {
        perror("not created");
        return NULL;
    }

    //loop all
    NODE *cursor = *head;
    do {
        if (cursor->data.info == s.info)  //comparison
            break;

        cursor = cursor->next;
    } while (cursor);

    return cursor;
}

/**
 * Finds middle node and then, makes a comparison.
 * Focuses always the middle, and compares with the middle.
 * At last steps, either b or e will be null, or b > e.
 * Works on sorted data.
 * <br><br>
 * @param head, If head is NULL, error occurs. If it is not sorted, error occurs.
 * @param s : DATA to search in nodes
 * @return : if founds, returns the node, otherwise NULL.
 */
NODE * binarySearch(NODE **head, DATA s) {
    if (!head) {
        perror("not created");
        return NULL;
    }
    if (!(*head)->header.sorted) {
        perror("invalid usage in an unsorted list");
        return NULL;
    }

    //compare middle, then divide again, till it found
    NODE *b = *head, *e = (*head)->header.tail, *m = NULL;
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
}

/**
 * Head node.
 * <br><br>
 * @param head
 * @return head
 */
NODE * getHead(NODE **head) {

    return *head;
}

/**
 * Last node
 * <br><br>
 * @param head
 * @return tail
 */
NODE * getTail(NODE **head) {

    return (*head)->header.tail;
}

/**
 * Locates middle node, using start and end node approach. So it can be called recursively.
 * Uses 2 pointers, one moves 1-step, second moves 2-steps. When faster reaches the end, slow points to the middle.
 * Better than mathematical (n/2) approach, if you can not have (or not meaningful) index-based reach.
 * Useful for binarySearch() method.
 *
 * @param b : beginning node. At first call, it is the head !
 * @param e : end node. At first call, it is the tail
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
 * <br><br>
 * @param head
 * @return size
 */
int size(NODE **head) {

    return (*head)->header.nodeCount;
}

/**
 * Sorted
 *
 * @param head
 * @return true if sorted, or false (default)
 */
bool isSorted(NODE **head) {

    return (*head)->header.sorted;
}

/**
 * Empty
 * <br><br>
 * @param head
 * @return size equals 0, true, or false
 */
bool isEmpty(NODE **head) {

    return ((*head)->header.nodeCount == 0) ? true : false;
}

/**
 * some internal stats, pointer's addr etc...
 * <br><br>
 * @param head
 */
void stats(NODE **head) {
    if (!head) {
        perror("not created");
        return;
    }

    printf("\n\n---------------stats----------------\n");

    NODE *cursor = *head;
    printf("seq data prev\t\t p\t\t next\n");
    int i = 0;
    do {
        printf("%d   %d\t %p\t %p\t %p\n", i, cursor->data.info, cursor->previous, cursor, cursor->next);

        i++;
        cursor = cursor->next;
    } while (cursor);

    printf("------------end of stats------------\n");
}

/**
 * Prints all nodes
 * <br><br>
 * @param head
 */
void display(NODE **head) {

    if (!head) {
        perror("not created");
        return;
    }

    NODE *cursor = *head;
    do {
        printf("%d  ", cursor->data.info);

        cursor = cursor->next;
    } while (cursor);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/list.h"

#ifndef ANSI_C_LIST_H
    typedef struct node {
        int info;

        struct node *link;
    } NODE;
#endif //ANSI_C_LIST_H


NODE *start = NULL;
NODE *last = NULL;
int nodes = 0;

/**
 * Returns *start pointer (1st node)
 *
 * @return start
 */
NODE * getFirst() {

    return start;
}

/**
 * Returns *last pointer (Nth node). Loops all nodes, performs as O(n)
 *
 * @return last
 */
NODE * getLast() {

    last = NULL;
    NODE *first = start;

    while (!last) {

        if (!first->link) {
            last = first;
            break;
        }

        first = first->link;
    };

    return last;
}

/**
 * Finds the node at node-index
 *
 * -> Not updates nodes.
 *
 * @param i (zero-based) node-index<br>
 * If,<br>
 *    i = 0, start                 O(1)<br>
 *    i = nodes-1, last            O(1)<br>
 *    i > 0 & i < nodes-1, loop    O(n)<br>
 *    i < 0 | i > nodes-1, error
 * @return if not found, NULL or the node
 */
NODE * getByIndex(int i) {
    if (!start) {
        perror("not initialized");
        return NULL;
    }

    //error
    if (i < 0 || i > count()-1) {
        perror("invalid node-index");
        return NULL;
    }

    //1st node
    if (i == 0) {
        return start;
    }

    //last
    if (i == count()-1) {
        return last;
    }

    //loop to find
    NODE *p = getFirst();
    int index = 0;

    do {
        if (index == i) {
            break;
        }

        index++;
        p = p->link;
    } while (p);

    return p;
}

/**
 * Finds t in nodes while looping all nodes. O(n)
 *
 * -> Not updates nodes.
 *
 * @param t search data
 * @return if not found, NULL or node
 */
NODE * getByData(int t) {
    if (!start) {
        perror("not initialized");
        return NULL;
    }

    NODE *p = getFirst();
    bool found = false;
    int index = 0;

    do {
        if (p->info == t) {    //todo: compare function
            found = true;
            break;
        }

        index++;
        p = p->link;
    } while (p);

    return found ? p : NULL;

}

/**
 * Creates 1st start node.
 * .. To initialize, use initialize()
 * .. To get start, use getFirst()
 *
 * -> Not updates nodes.
 *
 * @return start
 */
static NODE * create() {
    start = (NODE *)calloc(1, sizeof(NODE));
    if (!start) {
        perror("no allocation");
        return NULL;
    }

    start->info = -1;
    start->link = NULL;

    return start;
}

/**
 * Creates and adds first node.
 *
 * -> Set nodes=1.
 *
 * @param data for new node
 * @return start node
 */
static NODE * initialize(int data) {

    create();

    if (!start) {
        return NULL;
    }

    start->info = data;
    start->link = NULL;
    nodes = 1;

    return start;
}

/**
 * Appends new node to the end. If not initialized, then creates 1st node.
 *
 * -> Set nodes++.
 *
 * @param data
 * @return node that created
 */
NODE * append(int data) {

    if (!start)               //not initialized
        return initialize(data);

    //create new node
    NODE *tmp = (NODE *)calloc(1, sizeof(NODE));

    tmp->info = data;
    tmp->link = NULL;

    //find last node, and attach
    getLast()->link = tmp;
    nodes++;

    return tmp;
}

/**
 * Insert at the node-index
 *
 * @param k node-index to insert
 * If,
 *    k = 0, replace 1st, adjust start
 *    k = nodes-1, append last
 *    k > 0 & k < nodes, replace kth node
 *    k < 0 | k > nodes, error
 *
 * -> Set nodes++
 *
 * @param k node-index
 * @param data new data
 * @return if error, return NULL or return inserted node
 */
NODE * insertAt(int k, int data) {

    if (k < 0 || k > count()-1) {
        perror("invalid node-index");
        return NULL;
    }

    if (k == count() - 1) {
        return append(data);
    }

    //searchByIndex
    NODE *at = getByIndex(k);
    if (!at) {
        perror("not found");
        return NULL;
    }

    NODE *previousAt = k == 0 ? NULL : getByIndex(k-1);
    if (!previousAt && k != 0) {
        perror("not found");
        return NULL;
    }

    //create tmp data
    NODE *tmp = (NODE *) calloc(1, sizeof(NODE));
    if (!tmp) {
        perror("no allocation");
        return NULL;
    }

    tmp->info = data;
    tmp->link = at;

    if (k == 0)
        start = tmp;
    else
        previousAt->link = tmp;

    nodes++;                    //injected count update

    return tmp;
}

/**
 * Delete at the node-index <br>
 * If,<br>
 *    k = 0, delete 1st, adjust start<br>
 *    k = 0 & nodes-1=1, delete only and free<br>
 *    k = nodes-1, delete last<br>
 *    k > 0 & k < nodes, delete kth node<br>
 *    k < 0 | k > nodes, error<br>
 *
 * Set nodes++
 *
 * @param k node-index
 * @return if error, return -1 or return 0
 */
int deleteAt(int k) {

    //error
    if (k < 0 || k > count()-1) {
        perror("invalid node-index");
        return -1;
    }

    //only
    if (k == 0 && count() == 1) {
        free(start);
        nodes = 0;         //injected count update

        return 0;
    }

    NODE *tmp;
    NODE *tmpPrevious;

    //1st but not last
    if (k == 0) {
        tmp = getByIndex(k);
        if (!tmp) {
            return -1;
        }

        start = tmp->link;
        nodes--;           //injected count update

        tmp = NULL;

        return 0;
    }

    //last
    if (k == count()-1) {

        tmp = getByIndex(k-1);   //before last
        if (!tmp) {
            return -1;
        }

        tmp->link = NULL;
        nodes--;         //injected count update

        return 0;
    }

    //between
    tmp = getByIndex(k);
    tmpPrevious = getByIndex(k-1);
    if (!tmp || !tmpPrevious) {
        return -1;
    }

    tmpPrevious->link = tmp->link;
    nodes--;        //injected count update


    return 0;
}

/**
 * Reverses the list from start node.
 *
 * @return if error, returns old start, or new start node
 */
NODE * reverse() {
    NODE *previous, *next, *p;

    previous = NULL;
    p = getFirst();
    do {
       next = p->link;
       p->link = previous;
       previous = p;

       p = next;
    } while (p);

    start = previous;            //injected start

    return start;

}

/**
 * Finds t in nodes while looping all nodes. O(n)
 *
 * -> Not updates nodes.
 *
 * @param t search data
 * @return if not found, -1 or (zero-based) node-index
 */
int search(int t) {
    if (!start) {
        perror("not initialized");
        return -1;
    }

    NODE *p = getFirst();
    int index = 0;
    bool found = false;

    do {
        if (p->info == t) {    //todo: compare function
            found = true;
            break;
        }

        index++;
        p = p->link;
    } while (p);

    return found ? index : -1;
}

/**
 * Access all nodes from *start to the end. Performs O(n).
 * Also, updates the node count.
 *
 * -> Set 0, then nodes++.
 *
 * @param node: start node
 */
void display(NODE *node) {

    if (!node) {
        perror("not initialized");
        return;
    }

    nodes = 0;
    do {
        nodes++;                                               //injected count update
        printf("info=%d, addr=%p\n", node->info, node->link);

        node = node->link;
    } while (node);    //means node != NULL
}

/**
 * Nodes count. Injected into code, so calculates fast O(1).
 *
 * @return nodes
 */
int count() {

    return nodes;                                             //return injected node.
}
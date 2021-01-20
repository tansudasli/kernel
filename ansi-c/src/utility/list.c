#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

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

int search(NODE *node, int t) {
    if (!start) {
        perror("not initialized");
        return -1;
    }

    NODE *first = getFirst();
    int index = 0;
    bool found = false;

    do {
        if (first->info == t) {
            found = true;
            break;
        }

        index++;
        first = first->link;
    } while (first);

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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

NODE *start = NULL;

NODE * getFirst() {

    return start;
}

NODE * getLast() {

    NODE *last = NULL;
    NODE *first = start;

    do {

        if (first->link == NULL) {
            last = first;
            break;
        }

        first = first->link;
    } while (last == NULL);

    return last;
}

NODE * create() {
    start = (NODE *)calloc(1, sizeof(NODE));

    start->info = -1;
    start->link = NULL;

    return start;
}

/**
 * Creates and adds first node.
 *
 * @param data
 * @return start node
 */
NODE * initialize(int data) {
    create();

    start->info = data;
    start->link = NULL;

    return start;
}

/**
 * Appends new node to the end.
 *
 * @param data
 * @return
 */
NODE * append(int data) {

    if (!start) {
        perror("not initialized");
        printf("errr");
        return NULL;
    }

    //create new node
    NODE *tmp = (NODE *)calloc(1, sizeof(NODE));

    tmp->info = data;
    tmp->link = NULL;

    //find last node, and add
    getLast()->link = tmp;

    return tmp;
}

int search(NODE *node, int t) {
    if (!start) {
        perror("not initialized");
        printf("errr");
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
 * Access all nodes from *start to the end.
 *
 * @param node: start node
 */
void display(NODE *node) {

    do {
        printf("info=%d, addr=%p\n", node->info, node->link);

        node = node->link;
    } while (node);    //means node != NULL
}
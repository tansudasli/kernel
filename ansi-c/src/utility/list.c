#include <stdio.h>
#include <stdlib.h>

#include "list.h"

NODE *start = NULL;

NODE * getFirst() {

    return start;
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
 * Access all nodes from *start to the end.
 *
 * @param start addr
 */
void display(NODE *k) {

    NODE *tmp = k;
    do {
        printf("info=%d, addr=%p\n", tmp->info, tmp->link);

        tmp = tmp->link;
    } while (tmp != NULL);    //means data != NULL
}
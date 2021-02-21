#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../header/Queue.h"


NODE * create(DATA d) {
    NODE *front = (NODE *) calloc(1, sizeof(NODE));
    if (!front) {
        perror("no-allocation");
        return NULL;
    }

    //init
    front->header.rear = NULL;
    front->header.nodeCount = 0;
    front->link = NULL;

    //inject
    front->data.info = d.info;
    front->header.rear = front;
    front->header.nodeCount++;

    return front;
}

void enqueue(NODE **front, DATA d) {
    if (!front) {
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
    p->link = NULL;

    //append
    (*front)->header.rear->link = p;
    (*front)->header.rear = p;
    (*front)->header.nodeCount++;
}

NODE * dequeue(NODE **front) {
    if (!front) {
        perror("not created");
        return NULL;
    }

    //
    NODE *p = (*front)->link;

    //inject
    p->header.nodeCount = (*front)->header.nodeCount;
    p->header.rear = (*front)->header.rear;

    *front = p;

    return *front;
}

NODE * peek(NODE **front) {

    return *front;
}

int size(NODE **front) {

    return (*front)->header.nodeCount;
}

bool isEmpty(NODE **front) {

    return !*front ? true : false;
}
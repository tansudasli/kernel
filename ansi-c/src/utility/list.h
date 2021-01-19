
/**
 * Basic logic behind linked list.
 *
 *                    addr2             addr3
 * start (addr2) ...  info|(addr3) ...  info|add3
 */
typedef struct node {
    int info;

    struct node *link;
} NODE;



//interfaces
NODE * create();                //creates start node,
NODE * initialize(int);         //in the beginning, creates start node and adds first node
NODE * append(int);             //appends to the last element

NODE * getFirst();              //returns start node
NODE * getLast();               //returns last node

NODE * insertAt(NODE *, int, int);
NODE * insertAfter(NODE *, int, int);

NODE * delete(NODE *, int);

NODE * reverse(NODE *);

int search(NODE *, int);
void display(NODE *);
void count(NODE *);

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

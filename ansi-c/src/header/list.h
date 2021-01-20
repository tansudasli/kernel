
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
static NODE * create();                //creates start node,
static NODE * initialize(int);         //creates start node and adds to 1st node

NODE * getFirst();              //returns start node
NODE * getLast();               //returns last node

NODE * append(int);                    //creates 1st node, or appends to the last node
/**
 * insert at index (random)
 * search w/ data, and append to it (before/after). kinda sorting
 */
NODE * insertAt(NODE *, int, int);
NODE * insertAfter(NODE *, int, int);
NODE * insertBefore(NODE *, int, int);

NODE * delete(NODE *, int);

NODE * reverse(NODE *);

void display(NODE *);          //prints
int search(int);               //search in nodes by data, returns the node-index
NODE * search2(int);        //search in nodes by data, return the node
NODE * searchByIndex(int);       //return by given node-index
int count();                   //node count

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

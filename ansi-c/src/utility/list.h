
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
NODE * append(int);                    //creates 1st node, or appends to the last node

NODE * getFirst();              //returns start node
NODE * getLast();               //returns last node

NODE * insertAt(NODE *, int, int);
NODE * insertAfter(NODE *, int, int);

NODE * delete(NODE *, int);

NODE * reverse(NODE *);

int search(NODE *, int);       //
void display(NODE *);          //prints all nodes
int count();                   //Node count

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

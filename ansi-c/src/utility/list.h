
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
NODE * create();

NODE * insert(NODE *, int);         //at the end
NODE * insertAt(NODE *, int, int);
NODE * insertAtStart(NODE *, int);  //at the beginning
NODE * insertAfter(NODE *, int, int);

NODE * delete(NODE *, int);

NODE * reverse(NODE *);

void search(NODE *, int);
void display(NODE *);
void count(NODE *);

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

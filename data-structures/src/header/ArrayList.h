/**
 * Dynamic array
 *
 * Basic logic behind linked list.
 *
 *                    addr2             addr3
 * start (addr2) ...  info|(addr3) ...  info|add3
 *
 * @details Implementation of ArrayList.
 * @author tansudasli
 */


typedef struct node NODE;
struct node {
    int info;

    NODE *link;
};

NODE *start, *last;


//interfaces
static NODE * create();                //creates start node,
static NODE * initialize(int);         //creates start node and adds to 1st node

NODE * getFirst();              //returns 1st node
NODE * getLast();               //returns last node
NODE * getByIndex(int);         //return Nth node by node-index
NODE * getByData(int);          //return Nth node by data,

NODE * append(int);             //creates 1st node, or appends to the last node
NODE * insertAt(int, int);      //insert at 1st, middle, end
int deleteAt(int);              //delete at 1st, middle, last, only

NODE * reverse();               //reverse (1st becomes last etc..)

void display();                 //prints
int count();                    //node count //todo: rename as size()

int search(int);                //return node-index by data

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

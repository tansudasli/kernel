/**
 * Works as LIFO.
 *
 * Basic logic behind stack.
 *
 *      top             addr2             addr3
 *     (addr2) ...  info|(addr3) ...  info|NULL
 *
 * @details Only insert or remove the (top) 1st node. Insert/Delete between nodes not allowed.
 * @author tansudasli
 */


typedef struct node NODE;
struct node {
    int info;

    NODE *link;
};

NODE *top;                             //1st node

//interfaces
static NODE * create();                //creates start node,
static NODE * initialize(int);         //creates start node and adds to 1st node

NODE * getTop();                //returns 1st node
bool isEmpty();

void push(int);                 //inserts at 1st node
NODE * pop();                   //removes 1st node
NODE * peek();                  //returns 1st node without pop

void display();                 //prints
int size();                     //node count

#ifndef ANSI_C_STACK_H
#define ANSI_C_STACK_H

#endif //ANSI_C_STACK_H

/**
 * Works as FIFO.
 *
 * Basic logic behind queue.
 *
 *        front            addr2           addr3|rear
 *     info|(addr2) ...  info|(addr3) ...  info|NULL
 *
 * @details Insert (enqueue) to end, Remove (dequeue) from start. Insert/Delete between nodes not allowed.
 * @author tansudasli
 */

/**

 */
typedef struct node NODE;
struct node {
    int info;

    NODE *link;
};

NODE *front, *rear;                    //1st and last node

//interfaces
static NODE * create();                //creates start node,
static NODE * initialize(int);         //creates start node and adds to 1st node

NODE * getFront();                //returns 1st node
NODE * getRear();                 //returns last node
bool isEmpty();

NODE * enqueue(int);            //inserts at 1st node
NODE * dequeue();               //removes last node
NODE * peek();                  //returns 1st node without dequeue

void display();                 //prints
int size();                     //node count

#ifndef ANSI_C_STACK_H
#define ANSI_C_STACK_H

#endif //ANSI_C_STACK_H


#ifndef ANSI_C_QUEUE_H
#define ANSI_C_QUEUE_H

#endif //ANSI_C_QUEUE_H

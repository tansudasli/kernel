#include <stdbool.h>

/**
 * Works as LIFO.
 *
 * Basic logic behind stack.
 *
 *      top             addr2             addr3
 *   info|(addr2) ...  info|(addr3) ...  info|NULL
 *
 * @details Only insert or remove the (top) 1st node. Insert/Delete between nodes not allowed.
 * @author tansudasli
 */


typedef struct node NODE;
typedef struct data {
    int info;

} DATA;
struct node {
    DATA data;

    NODE *link;
};

NODE *top;                             //node which resides on top (naturally last in)

//interfaces
static void init();                    //initialize variables
NODE * create(DATA d);                 //O(1) - creates start node and adds to 1st node

void push(DATA d);                     //O(1) - inserts as top node
NODE * pop();                          //O(1) - removes top node
NODE * peek();                         //O(1) - returns top node without pop

bool isEmpty();

#ifndef ANSI_C_STACK_H
#define ANSI_C_STACK_H

#endif //ANSI_C_STACK_H

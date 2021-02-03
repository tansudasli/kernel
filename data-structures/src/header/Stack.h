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

typedef struct data {
    int info;

} DATA;

struct node {
    DATA data;

    NODE *link;
};

NODE *top;                             //node which resides on top (naturally last in)
static int nodeCount;
static bool sorted;

//interfaces
static void init();                    //initialize variables
static NODE * create(DATA d);          //creates start node and adds to 1st node

NODE * getTop();                //returns top node

void push(int);                 //inserts as top node
NODE * pop();                   //removes top node
NODE * peek();                  //returns top node without pop

void display();                 //prints
void stats();
int size();                     //node count
bool isEmpty();

#ifndef ANSI_C_STACK_H
#define ANSI_C_STACK_H

#endif //ANSI_C_STACK_H

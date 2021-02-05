#include <stdbool.h>

/**
 * Works as LIFO.<br>
 * <br>
 * Basic logic behind stack.<br>
 *
 *      top             addr2             addr3         <br>
 *   info|(addr2) ...  info|(addr3) ...  info|NULL      <br>
 * <br>
 * @details Only insert or remove the (top) 1st node. Insert/Delete between nodes not allowed.<br>
 * <br>
 * <br>Suitable for:
 * 1- Reversing<br>
 * 2- Backtracking, esp. for do something, if not ok, than reverse and try again. such as chess, maze problems.<br>
 * 3- Push/Pop/Compare: Symbol balancing, infix/postfix conversion (expression evaluation)<br>
 * 4- Do/Undo: Forward/Backward in browsers, tower of hanoi, histogram etc...<br>
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

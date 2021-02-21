#include <stdbool.h>

/**
 * Works as LIFO.<br>
 * First, Use create() then use push() and pop() methods.<br>
 * Can be used to create many stacks at the same time.
 *
 * <br>
 * Basic logic behind stack.<br>
 *
 *      top             addr2             addr3         <br>
 *   info|(addr2) ...  info|(addr3) ...  info|NULL      <br>
 * <br>
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

//interfaces

NODE * create(DATA d);                  //O(1) - creates 1st node, returns top

void push(NODE **top, DATA d);            //O(1) - inserts as top node
NODE * pop(NODE **top);                   //O(1) - updates top node, returns given old top
NODE * peek(NODE **top);                  //O(1) - returns top node without pop

void clean(NODE **top);                   //O(n) - deletes all nodes (free heap) todo: impl.

int size(NODE **top);                     //O(1) - node count todo: impl.
bool isEmpty(NODE **top);



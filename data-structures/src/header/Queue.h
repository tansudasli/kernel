#include <stdbool.h>

/**
 * Works as FIFO.
 *
 * - PriorityQueue is where priority can be changed using Comparator functions
 *
 * Basic logic behind queue. Implementing like a ArrayList is more efficient than implementing using 2-stacks!
 *
 *         front                              rear
 *                          addr2            addr3
 *     info|(addr2) ...  info|(addr3) ...  info|NULL
 *
 * @details Insert (enqueue) to end, Remove (dequeue) from start. Insert/Delete between nodes not allowed.
 * @author tansudasli
 */

/**

 */
typedef struct node NODE;
typedef struct header {     //to make O(1) for accessing last node, we need such struct.
    NODE *rear;             //And, global variable is not appropriate if you need to create more than one stack at the same time

    int nodeCount;
} HEADER;
typedef struct data {
    int info;

} DATA;
struct node {
    HEADER header;
    DATA data;

    NODE *link;
};

//interfaces

//todo: implement as PriorityQueue where default comparison is natural insert-order

NODE * create(DATA d);                      //O(1) - creates 1st node, returns front

void enqueue(NODE **front, DATA d);         //O(1) - inserts to rear
NODE * dequeue(NODE **front);               //O(1) - removes from front
NODE * peek(NODE **front);                  //O(1) - returns front node without dequeue

void clean(NODE **front);                   //O(n) - deletes all nodes (free heap) todo: impl.

int size(NODE **front);                     //O(1) - node count
bool isEmpty(NODE **front);                 //O(1) - true if empty


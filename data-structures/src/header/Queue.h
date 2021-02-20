/**
 * Works as FIFO.
 *
 * Basic logic behind queue.
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
typedef struct data {
    int info;

} DATA;
struct node {
    DATA data;

    NODE *link;
};

//interfaces

NODE * create(DATA d);                        //creates 1st node, returns front

NODE * enqueue(NODE **front, DATA d);         //inserts to rear
NODE * dequeue(NODE **front);                 //removes from front
NODE * peek(NODE **front);                    //returns front node without dequeue

void clean(NODE **t);                         //deletes all nodes (free heap) todo: impl.

bool isEmpty(NODE **t);


#include <stdbool.h>

/**
 * Dynamic array
 *
 * Basic logic behind linked list. A bit different usual start-last architecture.
 * Normally, start is a kind of 1st node. That creates problems esp. for doublyLinked lists, binarySearch or finding the middle.
 * So, below design (head and tail approach) is more concise and simple.
 * In this design, head is actually same as the 1st node.
 * //todo: More over, We can make one more enhancement. Head pointer points to the 1st node pointer, and not becomes same as 1st node.
 * <br>
 * --> circleLinkedList are trivial.<br>
 * --> doublyLinkedList (handling previous link) is good for searching<br>
 *
 *
 * p        head                                              tail              <br>
 *          addr0                     addr1                   addrN             <br>
 *     NULL|info|(addr1)   ...   addr0|info|(addr2) ...  addr2|info|NULL        <br>
 * <br>
 *
 * @details Implementation of ArrayList (Linked List).
 * <br>- Insert/Remove to end/beginning/between possible.
 * <br>- Optimized for many features O(1) instead of O(n)
 * <br>- First create() then use append(), attach() or insert() methods to build ArrayList.
 * @author tansudasli
 */

typedef struct node NODE;
typedef enum {BEFORE, AFTER} POSITION;

typedef struct header {

} HEADER;
typedef struct data {
    int info;

} DATA;
struct node {
    HEADER header;
    DATA data;            //todo: anytype data: info can be void* to handle any type of data

    NODE *next;
    NODE *previous;
};

NODE *head, *tail;
int nodeCount;
bool sorted;

//interfaces
static void init();             //init defaults
NODE * create(DATA d);          //creates start node

NODE * getFirst();                   //O(1) - returns first node
NODE * getLast();                    //O(1) - returns last node
NODE * getMiddle(NODE *b, NODE *e);  //O(logn) - returns in the middle node

NODE * search(DATA s);          //O(n) - search                                //data dependent comparison!
NODE * search2(int s);          //search by int in DATA struct                 //todo: impl.
NODE * search3(char* s);        //search by string in DATA struct              //todo: impl.
NODE * binarySearch(DATA s);    //O(logn) - search by splitting into middles   //data dependent comparison!

void append(DATA d);                            //O(1) - appends to the last
void attach(DATA d);                            //O(1) - inserts at the beginning
void insert(DATA s, POSITION pos, DATA d);      //O(n) - insert between 1st and last, append/attach where necessary
                                                                               //todo: search() vs binarySearch() optimize
void insertSorted(DATA d);                      //O(n) - insert as sorted

void replace(DATA s, DATA r);                   //O(n) - replace s with r          //todo: impl.
void swap(DATA s, DATA r);                      //sway s with r, and vise versa... //todo: impl.

int delete(DATA s);             //O(n) - delete at 1st, middle, last, only  //todo: impl.
int clean();                    //deletes all records (free heap)           //todo: add a method to delete all records
                                                                            //todo: add onexit signal

NODE * reverse();               //O(n) - reverse (1st becomes last etc..)   //todo: impl.

void display();                 //O(n) - prints                             //data dependent printf!
void stats();                   //O(n) - print some stat data
int size();                     //O(1) - node count
bool isSorted();                //O(1) - default not sorted                 //todo: impl.

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

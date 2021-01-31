#include <stdbool.h>

/**
 * Dynamic array
 *
 * Basic logic behind linked list.
 *
 *      start             addr2             addr3
 *     (addr2)   ...   info|(addr3) ...  info|NULL
 *
 * @details Implementation of ArrayList. Insert/Remove to end/beginning/between possible.
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

NODE *start, *last;
int nodeCount;
bool sorted;

//interfaces
static void init();             //init defaults
NODE * create();                //creates start node

NODE * getFirst();              //returns first node
NODE * getLast();               //returns last node

NODE * search(DATA s);          //search node by data,    //todo: data dependent comparison!

void append(DATA d);                              //appends to the last
void attach(DATA d);                              //inserts at the beginning
void insert(DATA s, POSITION pos, DATA d);        //insert between first and last   //todo: add insert sorted flavor
void replace(DATA s, DATA r);                     //todo: replace s with r

int delete(DATA s);             //delete at 1st, middle, last, only
int clean();                    //deletes all records (free heap)    //todo: add a method to delete all records

NODE * reverse();               //reverse (1st becomes last etc..)

void display();                 //prints                  //todo: data dependent printf!
void stats();                   //print some stat data
int size();                     //node count
bool isSorted();                //default not sorted

#ifndef ANSI_C_LIST_H
#define ANSI_C_LIST_H

#endif //ANSI_C_LIST_H

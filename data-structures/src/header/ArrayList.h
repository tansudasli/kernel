#include <stdbool.h>

/**
 * Dynamic array
 *
 * Basic logic behind linked list. A bit different usual start-last architecture.
 * Normally, start is a kind of Dummy 1st node. That creates problems esp. for doublyLinked lists, binarySearch or finding the middle.
 * So, below design (head and tail approach) is more concise and simple.
 * <br>
 * <br>
 * On the other hand, there are 3 main considerations.
 * <br>
 * 1- Taking head from client like f(NODE **head) vs holding head as a global. The latter means
 *   you can not create two ArrayList at the same time. So that it can not be a library.
 * 2- How can decrease some O(n) operations to O(1). Such as counting nodes, getting last node etc..
 *   In previous design, (getting head from client), you can not hold them as global variables.
 *   So you need a HEADER section in your NODE design.
 * 3- to optimize search O(n). to do that yo need to get last and middle nodes faster.
 *   So you can leverage binarySearch O(logn).
 *   To do this you need to hold previous link, and sorted inserts.
 *
 * <br>
 * ArrayList is also critical data structure to build HashMaps which is the combination of Array + ArrayList !!
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
 * <br>
 * --> circleLinkedList are trivial.<br>
 * --> doublyLinkedList (handling previous link) is good for searching<br>
 * @author tansudasli
 */

typedef struct node NODE;
typedef enum {BEFORE, AFTER} POSITION;

typedef struct header {  //to make O(1) for accessing last node, we need such struct.
    NODE *tail;          //And, global variable is not appropriate if you need to create more than one stack at the same time

    int nodeCount;
    bool sorted;
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


//interfaces
//todo: make  sorted as optional
NODE * create(DATA d, bool sorted);            //O(1) - creates head node, and returns to client

NODE * getHead(NODE **head);                   //O(1) - returns first node
NODE * getTail(NODE **head);                   //O(1) - returns last node
NODE * getMiddle(NODE *b, NODE *e);            //O(logn) - returns the middle node

NODE * search(NODE **head, DATA s);            //O(n) - search
NODE * search2(NODE **head, bool (*comparison) (int v1, int s));    //O(n) - search todo: impl.

NODE * binarySearch(NODE **head, DATA s);      //O(logn) - search by splitting into middles

void append(NODE **head, DATA d);              //O(1) - appends to the last
void attach(NODE **head, DATA d);              //O(1) - replaces head with new node

void insert(NODE **head, DATA s, DATA d, POSITION pos);      //O(n) - insert between 1st and last, append/attach where necessary
void insert2(NODE **head, NODE * (*search) (NODE **head, DATA s), DATA d, POSITION pos); //todo: gets search func. as function pointer :) why not
void insertSorted(NODE **head, DATA d);                      //O(n) - insert as descending sorted
void insertSorted2(NODE **head, DATA d, bool (*comparison) (int s, int d)); //todo: to enable ascending mode sorting etc..

void replace(NODE **head, DATA s, DATA r);     //O(n) - replace s with r     todo: impl.
void swap(NODE **head, DATA s, DATA r);        //O(n) - swap s with r, and vise versa... todo: impl.
NODE * reverse(NODE **head);                   //O(n) - reverse todo: impl.

int delete(NODE **head, DATA s);               //O(n) - delete                             todo: impl.
int clean();                                   //O(n) - deletes all nodes (free heap)      todo: impl.


void display(NODE **head);                 //O(n) - prints all
void stats(NODE **head);                   //O(n) - print some stat data
int size(NODE **head);                     //O(1) - node count
bool isSorted(NODE **head);                //O(1) - sort status
bool isEmpty(NODE **head);                 //O(1) - size status


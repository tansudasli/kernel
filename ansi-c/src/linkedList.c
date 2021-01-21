#include <stdio.h>
#include <stdlib.h>

#include "list.h"

NODE *data = NULL;

int main (int argc, char **argv) {


    //create and add 1 node, w/ data 1
    append(1);  //initialize. then
    append(2);  //  + 1 node
    append(3);  //  + 1 node
    insertAt(1, 5);  //  + 1 node
    insertAt(0, 7);  //at the beginning
    insertAt(4, 17); //at the last
//    insertAt(-3, 5);  //  invalid index

    printf("\nnodes= %d \n", count());

    //show
    display(getFirst());

    //search
    printf("\n1 is at index=%d 's value is, %d, %d", search(1), getByData(1)->info, getByIndex(search(1))->info);
    printf("\n2 is at index=%d", search(2));
    printf("\n150 is at index=%d\n", search(150));   //-1 not found

    //delete
//      deleteAt(-1);   //invalid index
//      deleteAt(0);    //1st and only
    deleteAt(0);    //1st and not last
    deleteAt(4);    //last
    deleteAt(2);   //between

    printf("\nnodes= %d \n", count());
    display(getFirst());


    return 0;
}
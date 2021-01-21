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
    printf("\n2 is at index=%d 's value is, %d, %d", search(2), getByData(2)->info, getByIndex(search(2))->info);
    printf("\n150 is at index=%d", search(150));   //-1 not found

    //delete


    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "header/LinkedList.h"


int main (int argc, char **argv) {


    //insert as sorted
    DATA n[] = {3, 59, 8, 9, 10, 7, 31, 37, 23, 25, 42, 44, 47, 24, 50, 55, 54, 53, 52, 1, 5};
    int lN = sizeof(n) / sizeof(n[0]);

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < lN; i++)
        printf("%d  ", n[i].info);
    printf("\n------------sorted------------------\n");

    //init
    NODE *headN = create(n[0], true);

    for (int i = 1; i < lN; i++)
       insertSorted(&headN, n[i]);

    //
    display(&headN);

//    /**
//    NODE *cursor = getHead(&headN);
//    while (cursor) {
//        printf("%d ", cursor->data.info);
//
//        cursor = cursor->next;
//    }
//     */


    //
    stats(&headN);

    assert(size(&headN) == lN);   // printf("\ntotal of nodes=%d", size(&headN));
    assert(isSorted(&headN)); //printf("\nisSorted=%d", isSorted(&headN));

    return 0;
}
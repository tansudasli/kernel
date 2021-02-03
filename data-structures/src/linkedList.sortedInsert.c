#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"

NODE *p = NULL;

int main (int argc, char **argv) {


    //creates sorted Array List
    //not sorted array

    DATA n[] = {5, 3, 10, 9, 8, 57, 60, 35, 1, 12, 2}; int l = 11;
//    DATA n[] = {6, 5, 3, 2, 1}; int l = 5;

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < l; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");

    //init
    p = create(n[0]);

    for (int i = 1; i < l; i++)
       insertSorted(n[i]);


    //
    display();

    /**
    p = getFirst();
    while (p) {
        printf("%d ", p->data.info);

        p = p->next;
    }
     */


    //
    stats();

    printf("\ntotal of nodes=%d", size());
    printf("\nisSorted=%d", isSorted());


    return 0;
}
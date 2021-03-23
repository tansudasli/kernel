#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "header/LinkedList.h"

int main (int argc, char **argv) {

    //binarySearch - O(logn)

    DATA n[] = {3, 5, 8, 9, 10, 20, 31, 37, 39, 41, 42, 44, 47, 49, 50, 51, 52, 53, 54, 55, 59};
    int lN = sizeof(n) / sizeof(n[0]);

    //init & initialize
    NODE *headN = create(n[0], true);

    for (int i = 1; i < lN; i++)
        append(&headN, n[i]);

    //
    printf("\n");
    display(&headN);

    //search
    printf("\n----------------binarySearch ---------------------");
    NODE *f;
    DATA tmp;
    int counter = 0;
    for (int i = 0; i < 60; i++) {
        tmp.info = i;

        f = binarySearch(&headN, tmp);
        !f ? counter : counter++;
        !f ? printf("\nnot found= %d", i) : printf("\nfound on %p as %d", f, f->data.info);
    }

    assert(counter == lN);   //printf("\n%d records found", counter);

    //
    stats(&headN);

    return 0;
}
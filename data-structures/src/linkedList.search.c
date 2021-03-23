#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "header/LinkedList.h"

int main (int argc, char **argv) {

    //search - O(n)

    DATA n[] = {5, 8, 3, 10, 20, 31, 51, 41, 35, 32, 2, 4};
    int lN = sizeof(n) / sizeof(n[0]);

    //init & initialize
    NODE *headN = create(n[0], false);

    for (int i = 1; i < lN; i++)
       append(&headN, n[i]);

    DATA k; k.info = 1;
    insert(&headN,n[0], k, BEFORE);
    lN++;

    k.info = 6;
    insert(&headN,n[11], k, AFTER);
    lN++;

    k.info = 29;
    insert(&headN,n[6], k, AFTER);
    lN++;

    //
    printf("\n");
    display(&headN);

    //search
    printf("\n----------------search ---------------------");
    NODE *f;
    DATA tmp;
    int counter = 0;
    for (int i = 0; i < 60; i++) {
        tmp.info = i;

        f = search(&headN, tmp);
        !f ? counter : counter++;
        !f ? printf("\nnot found= %d", i) : printf("\nfound on %p as %d", f, f->data.info);
    }

    assert(counter == lN);   //printf("\n%d records found", counter);

    //
    stats(&headN);

    return 0;
}
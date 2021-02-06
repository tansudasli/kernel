#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"

NODE *p = NULL;

int main (int argc, char **argv) {



    //add to last
    //creates sorted intentionally!
    DATA n[] = {5, 8, 10, 20, 31, 57};

    //init
    p = create(n[0]);

    int l = sizeof(n)/sizeof(n[0]);
    for (int i = 1; i < l; i++)
       append(n[i]);

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < 6; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");


    //attach to beginning
    DATA d1, d2; d1.info = 3; d2.info = 2;
    printf("attach %d\n", d1.info); attach(d1);
    printf("attach %d\n", d2.info); attach(d2);

    //
    display();
    /**
    p = getFirst();
    while (p) {
        printf("%d ", p->data.info);

        p = p->next;
    }
     */

    //insert (before)
    d1.info = 4; d2.info = 6;
    printf("\ninserting %d before %d..", d1.info, n[0].info);
    insert(n[0], BEFORE, d1);

    printf("\ninserting %d after %d..", d2.info, n[0].info);
    insert(n[0], AFTER, d2);

    d2.info = 60;
    printf("\ninserting %d after last..", d2.info);
    insert(n[5], AFTER, d2);

    d1.info = 2; d2.info = 1;
    printf("\ninserting %d before start..", d2.info);
    insert(d1, BEFORE, d2);

    printf("\n");

    display();


    //
    stats();

    printf("\ntotal of nodes=%d", size());


    return 0;
}
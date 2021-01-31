#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"


NODE *p = NULL;

int main (int argc, char **argv) {

    //init
    p = create();

    //add to last
    DATA n[] = {5, 3, 10, 2, 1, 17};


    for (int i = 0; i < 6; i++)
       append(n[i]);

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < 6; i++)
        printf("%d  ", n[i].info);
    printf("\n------------original------------\n");


    //attach to beginning
    printf("attach %d\n", n[3].info); attach(n[3]);
    printf("attach %d\n", n[3].info); attach(n[3]);


    //
    display();
//    p = getFirst();
//    while (p) {
//        printf("%d ", p->data.info);
//
//        p = p->next;
//    }

    //search
    printf("\nseeking %d..", n[5].info);
    NODE *f = search(n[5]);
    f == NULL ? printf("not found") : printf("found on %p as %d", f, f->data.info);

    printf("\nseeking %d..", n[0].info);
    f = search(n[0]);
    f == NULL ? printf("not found") : printf("found on %p as %d", f, f->data.info);

    //insert (before)
    DATA d; d.info = 51;
    printf("\ninserting %d before %d..", d.info, n[0].info);
    insert(n[0], BEFORE, d);

    printf("\ninserting %d after %d..", d.info, n[0].info);
    insert(n[0], AFTER, d);

    printf("\ninserting %d after last..", d.info);
    insert(n[5], AFTER, d);

    printf("\ninserting %d before start..", d.info);
    insert(n[3], BEFORE, d);

    printf("\n");

    display();

    //


    //
    stats();

    printf("\ntotal of nodes=%d", size());


    return 0;
}
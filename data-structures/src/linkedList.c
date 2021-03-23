#include <stdio.h>
#include <stdlib.h>

#include "header/LinkedList.h"


int main (int argc, char **argv) {

    //add to last
    //creates sorted intentionally!
    DATA n[] = {5, 8, 10, 20, 31, 57};
    int l = sizeof(n) / sizeof(n[0]);

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < 6; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");


    //init, create then append or attach or insert
    NODE *head = create(n[0], false);

    for (int i = 1; i < l; i++)
       append(&head, n[i]);

    //attach to beginning
    DATA d1, d2;
    d1.info = 3;
    d2.info = 2;
    printf("attach %d\n", d1.info); attach(&head, d1);
    printf("attach %d\n", d2.info); attach(&head, d2);

    //
    display(&head);

//    NODE *h1 = getHead(&head);
//    while (h1) {
//        printf("----%d ", h1->data.info);
//
//        h1 = h1->next;
//    }

    //insert (before)
    d1.info = 4;
    d2.info = 6;
    printf("\ninserting %d before %d..", d1.info, n[0].info);
    insert(&head, n[0], d1, BEFORE);

    printf("\ninserting %d after %d..", d2.info, n[0].info);
    insert(&head, n[0], d2, AFTER);

    d2.info = 60;
    printf("\ninserting %d after last..", d2.info);
    insert(&head, n[5], d2, AFTER);
//
//    d1.info = 2;
//    d2.info = 1;
//    printf("\ninserting %d before start..", d2.info);
//    insert(&head, d1, d2, BEFORE);

    printf("\n");

    display(&head);

    //
    stats(&head);

    printf("\ntotal of nodes=%d", size(&head));

    return 0;
}
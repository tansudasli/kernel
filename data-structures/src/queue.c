#include <stdio.h>
#include <stdlib.h>

#include "header/Queue.h"

//gcc src/queue.c src/collection/Queue.c -o out/queue  && out/queue
int main (int argc, char **argv) {

    //queue
    DATA n[] = {5, 8, 10, 20, 31, 57};
    int l = sizeof(n) / sizeof(n[0]);

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < 6; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");


    //init, create then append or attach or insert
    NODE *front = create(n[0]);

    for (int i = 1; i < l; i++)
        enqueue(&front, n[i]);

    NODE *tmp = dequeue(&front);
    printf("got front: %d\n", tmp->data.info);

    tmp = dequeue(&front);
    printf("got front: %d\n", tmp->data.info);

    printf("enqueue: 22\n");
    DATA k; k.info = 22;
    enqueue(&front, k);

    printf("enqueue: 11\n\n");
    k.info = 11;
    enqueue(&front, k);

    while (front) {
        printf("%d  ", front->data.info);

        front = front->link;
    }

    while (front) {
        dequeue(&front);

        front = front->link;
    }

    printf("\ndequeued all...");
    printf("isEmpty= %d", isEmpty(&front));


    printf("\n------------------------------\n");

    return EXIT_SUCCESS;
}
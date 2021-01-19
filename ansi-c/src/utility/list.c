#include <stdio.h>
#include <stdlib.h>

#include "list.h"

NODE *start = NULL;


NODE * create() {
    start = (NODE *)calloc(1, sizeof(NODE));

    if (!start) {
        perror("no allocation");

        return NULL;
    }

    start->info = 0;
    start->link = start;

    return start;
}

void display(NODE *data) {

    do {
        printf("info=%d, addr=%p", data->info, data->link);

        data++;
    } while (!data);    //means data == NULL
}
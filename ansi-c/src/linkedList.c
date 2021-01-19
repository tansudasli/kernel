#include <stdio.h>
#include <stdlib.h>

#include "utility/list.h"

NODE *data = NULL;

int main (int argc, char **argv) {

    //create
//    start = create();
//    display(start);


    //create and add 1 node
    initialize(1);
    append(2);
    append(3);

    display(getFirst());

    printf("\n%d %p", getFirst()->info, getFirst()->link);
    printf("\n%d %p\n", getLast()->info, getLast()->link);

    printf("\nindex=%d", search(NULL, 1));
    printf("\nindex=%d", search(NULL, 2));
    printf("\nindex=%d", search(NULL, 5));


    return 0;
}
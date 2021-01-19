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
    printf("\n%d %p", getLast()->info, getLast()->link);



    return 0;
}
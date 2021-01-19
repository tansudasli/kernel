#include <stdio.h>
#include <stdlib.h>

#include "utility/list.h"

NODE *data = NULL;

int main (int argc, char **argv) {

    //create
//    start = create();
//    display(start);

    //create and add 1 node
    data = initialize(1);
    display(data);



    return 0;
}
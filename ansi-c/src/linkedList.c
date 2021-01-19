#include <stdio.h>
#include <stdlib.h>

#include "utility/list.h"

int main (int argc, char **argv) {

    //initialized
    NODE *data = create();

    data ? display(data) : printf("no allocation error");

    return 0;
}
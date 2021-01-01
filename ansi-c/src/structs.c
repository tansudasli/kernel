#include <stdio.h>
#include "header/structs.h"

//  gcc src/structs.c src/utility/initialize.c -o out/structs  && out/structs
int main(int argc, char **argv) {

    initializeDataset();

    //print dataset
    CD this;
    printf("Title  | Rating\n");
    for (int i = 0; i < NUMBER_OF_CDS; i++) {
        this = cdDataset[i];

        printf("%s | %u \n", this.title, this.rating);
    }

    return 0;
}
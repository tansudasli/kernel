#include <stdio.h>
#include "header/structs.h"

//  gcc src/structs.c src/utility/initialize.c -o out/structs  && out/structs
int main(int argc, char **argv) {

    initializeDataset();

    printf("-------Access w/ values--------\n");
    printf("Title \t\t\t| Rating\n");

    CD this;
    for (int i = 0; i < NUMBER_OF_CDS; i++) {
        this = cdDataset[i];

        printf("%s \t| %u  \t| %p \n", this.title, this.rating, (CD *) &cdDataset[i]);
    }

    printf("-------Access w/ pointer--------\n");
    printf("Title \t\t\t| Rating\n");

    CD *that = cdDataset;
    for (int i = 0; i < NUMBER_OF_CDS; i++) {

        printf("%s \t| %u  \t| %p \n", that->title, that->rating, that);
        that++;
    }

    printf("------------------\n");
    printf("size of CD=%lu\n", sizeof(cdDataset));
    printf("size for first record CD=%lu\n", sizeof(cdDataset)/NUMBER_OF_CDS);

    return 0;
}
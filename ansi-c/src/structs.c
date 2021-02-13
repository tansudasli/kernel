#include <stdio.h>
#include <string.h>

#ifndef NUMBER_OF_CDS
#define NUMBER_OF_CDS 2
#endif //NUMBER_OF_CDS

typedef enum score {
    TERRIBLE, BAD, AVERAGE, GOOD, EXCELLENT
} SCORE;

typedef struct cd {
    char title[50];
    char artist[50];
    int trackCount;
    SCORE rating;
} CD; //So we can use like native int/char type...

CD cdDataset[NUMBER_OF_CDS];

//gcc src/structs.c -o out/structs  && out/structs
int main(int argc, char **argv) {

    //initialize
    strcpy(cdDataset[0].title, "Once upon a time");
    strcpy(cdDataset[0].artist, "Ali Veli");
    cdDataset[0].trackCount = 10;
    cdDataset->rating = TERRIBLE;

    strcpy(cdDataset[1].title, "Just run forest");
    strcpy(cdDataset[1].artist, "Mali Dali");
    cdDataset[1].trackCount = 1;
    cdDataset->rating = AVERAGE;

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
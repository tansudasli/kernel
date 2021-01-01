#include <stdio.h>
#include <string.h>

#define NUMBER_OF_CDS 2

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

void initializeDataset() {
    strcpy(cdDataset[0].title, "Once upon a time");
    strcpy(cdDataset[0].artist, "Ali Veli");
    cdDataset[0].trackCount = 10;
    cdDataset->rating = TERRIBLE;

    strcpy(cdDataset[1].title, "Just run forest");
    strcpy(cdDataset[1].artist, "Mali Dali");
    cdDataset[1].trackCount = 1;
    cdDataset->rating = AVERAGE;
}

// gcc -o out/structs src/structs.c  && out/structs
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


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


void initializeDataset();

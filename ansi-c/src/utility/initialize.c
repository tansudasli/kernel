#include <string.h>
#include "../header/structs.h"

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


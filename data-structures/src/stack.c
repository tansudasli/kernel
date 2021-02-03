#include <stdio.h>
#include <stdlib.h>

#include "header/Stack.h"

NODE *p = NULL;

int main (int argc, char **argv) {



    //add to last
    //creates sorted intentionally!
    DATA n[] = {5, 8, 10, 20, 31, 57};

    //print original
    printf("------------original------------\n");
    for (int i = 0; i < 6; i++)
        printf("%d  ", n[i].info);
    printf("\n------------------------------\n");





    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"


NODE *p = NULL;

int main (int argc, char **argv) {


    //add to last
    //created as sorted intentionally!

//    DATA n[] = {5, 8, 10, 20, 31, 57}; int l=6;
    DATA n[] = {5, 6, 8, 10, 12, 20, 21, 22, 31, 57, 72}; int l=11;

    //init
    p = create(n[0]);

    for (int i = 1; i < l; i++)
       append(n[i]);

    display();

    //binarySearch
    NODE *f = NULL;
    printf("\n---------binarySearch---------------------");
    for (int i = 0; i < l; i++) {
        f = binarySearch(n[i]);
        f == NULL ? printf("\nnot found= %d", n[i].info) : printf("\nfound on %p as %d", f, f->data.info);
    }

    //not found cases
    printf("\n---------binarySearch - notFound------------");
    f = NULL;
    DATA tmp;
    for (int i = 101; i >= 0; i--) {
        tmp.info = i;
        f = binarySearch(tmp);
        f == NULL ? printf("\nnot found= %d", i) : printf("\nfound on %p as %d", f, f->data.info);
    }

    printf("\n");

    //
    stats();

    return 0;
}
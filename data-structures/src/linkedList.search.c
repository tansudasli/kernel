#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"


NODE *p = NULL;

int main (int argc, char **argv) {

    //init
    p = create();

    //add to last
    //created as sorted intentionally!
    int l = 6;
    DATA n[] = {5, 8, 10, 20, 31, 57};

    for (int i = 0; i < 6; i++)
       append(n[i]);

    //
    display();

    //search
    NODE *f;
    printf("\nO(n) search\n");
    for (int i = 0; i < l; i++) {
        f = search(n[i]);
        f == NULL ? printf("\nnot found") : printf("\nfound on %p as %d", f, f->data.info);
    }
    DATA z; z.info = 100;
    f = search(z);
    f == NULL ? printf("\nnot found= %d", z) : printf("\nfound on %p as %d", f, f->data.info);

    //binarySearch
    printf("\n\nO(logn) binarySearch");
    for (int i = 0; i < l; i++) {
        f = binarySearch(n[i]);
        f == NULL ? printf("\nnot found= %d", i) : printf("\nfound on %p as %d", f, f->data.info);
    }
    DATA k; k.info = 100;
    f = binarySearch(k);
    f == NULL ? printf("\nnot found= %d", k.info) : printf("\nfound on %p as %d", f, f->data.info);

    printf("\n");

    //
    stats();

    return 0;
}
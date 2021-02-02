#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"


NODE *p = NULL;

int main (int argc, char **argv) {



    //add to last
    //created as sorted intentionally!
    int l = 6;
    DATA n[] = {5, 8, 10, 20, 31, 57};

    //init
    p = create(n[0]);

    for (int i = 1; i < 6; i++)
       append(n[i]);

    //
    display();

    //search
    NODE *f;
    printf("\n----------------search---------------------\n");
    for (int i = 0; i < l; i++) {
        f = search(n[i]);
        f == NULL ? printf("\nnot found") : printf("\nfound on %p as %d", f, f->data.info);
    }

    printf("\n----------------search - notfound---------------------");
    DATA tmp;
    for (int i = 0; i < 30; i++) {
        tmp.info = i;
        f = search(tmp);
        f == NULL ? printf("\nnot found= %d", i) : printf("\nfound on %p as %d", f, f->data.info);
    }


    printf("\n");

    //
    stats();

    return 0;
}
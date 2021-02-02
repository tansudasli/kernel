#include <stdio.h>
#include <stdlib.h>

#include "header/ArrayList.h"


NODE *p = NULL;

int main (int argc, char **argv) {

    //init
    p = create();

    //add to last
    //created as sorted intentionally!
    //even or odd is important
    int l = 11;
//    DATA n[] = {5, 8, 10, 20, 31, 57};
    DATA n[] = {5, 6, 8, 10, 12, 20, 21, 22, 31, 57, 72};

    for (int i = 0; i < l; i++)
       append(n[i]);

    //
    display();

    //check middle func : start .....to.....
    printf("\nstart .....to.....");
    NODE *m = getMiddle(getFirst()->next, getLast());
    NODE *last = getLast();
    for (int i = 0; i < l; i++) {
       printf("\n%d....m....%d=> m=%d", getFirst()->next->data.info, last->data.info, m->data.info);

       last = m;
       m =  getMiddle(getFirst()->next, m);
    }

    printf("\n\n");
    printf(" .....to.....last");
    m = getMiddle(getFirst()->next, getLast());
    NODE *first = getFirst()->next;
    for (int i = 0; i < l; i++) {
        printf("\n%d....m....%d=> m=%d",  first->data.info, getLast()->data.info, m->data.info);

        first = m;
        m =  getMiddle(m, getLast());
    }

    printf("\n");

    display();

    //
    stats();


    return 0;
}
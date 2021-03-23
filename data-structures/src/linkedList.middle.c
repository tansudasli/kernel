#include <stdio.h>
#include <stdlib.h>

#include "header/LinkedList.h"


int main (int argc, char **argv) {


    //find the middle node for 2 different ArrayList at the same time. So check library expectations also

    DATA z[] = {5, 8, 10, 20, 31, 57}; int lz = sizeof(z) / sizeof(z[0]);
    DATA n[] = {5, 6, 8, 10, 12, 20, 21, 22, 31, 57, 72}; int ln = sizeof(n) / sizeof(n[0]);

    //init & initialize
    NODE *headOfN = create(n[0], false);
    NODE *headOfZ = create(z[0], false);

    for (int i = 1; i < ln; i++)
       append(&headOfN, n[i]);

    for (int i = 1; i < lz; i++)
        append(&headOfZ, z[i]);

    //
    display(&headOfN); printf("\n");

    //check middle func : start .....to.....
    printf("\nstart .....to.....medium");
    NODE *m = getMiddle(getHead(&headOfN), getTail(&headOfN));
    NODE *last = getTail(&headOfN);

    for (int i = 0; i < ln; i++) {
       printf("\n%d....m....%d=> m=%d", getHead(&headOfN)->data.info, last->data.info, m->data.info);

       last = m;
       m =  getMiddle(getHead(&headOfN), m);
    }

    printf("\n\n");
    display(&headOfZ);

    //check middle func : start .....to.....
    printf("\nstart .....to.....medium");
    NODE *mZ = getMiddle(getHead(&headOfZ), getTail(&headOfZ));
    NODE *lastZ = getTail(&headOfZ);

    for (int i = 0; i < lz; i++) {
        printf("\n%d....m....%d=> m=%d", getHead(&headOfZ)->data.info, lastZ->data.info, mZ->data.info);

        lastZ = mZ;
        mZ =  getMiddle(getHead(&headOfZ), mZ);
    }

    printf("\n\n");

    display(&headOfN);

    printf("\nmedium.....to.....last");
    m = getMiddle(getHead(&headOfN), getTail(&headOfN));
    NODE *first = getHead(&headOfN);

    for (int i = 0; i < ln; i++) {
        printf("\n%d....m....%d=> m=%d",  first->data.info, getTail(&headOfN)->data.info, m->data.info);

        first = m;
        m =  getMiddle(m, getTail(&headOfN));
    }

    printf("\n");

    //
    stats(&headOfN);
    stats(&headOfZ);

    return 0;
}
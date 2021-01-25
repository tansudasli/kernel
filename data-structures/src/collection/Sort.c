
#include "../header/Sort.h"


/**
 * Selection Sort in ascending order
 * O(n^2)
 *
 * @param s: addr of int[], and updates the input in place
 * @param length: size of s
 * @param direction: asc is default, either desc
 */
void sort2 (int *s, int length, DIRECTION direction) {    //todo: add descending flavor
    int index, tmp;

    for (int i = 0; i < length; i++) {
        index = i;

        for (int j = i + 1; j < length; j++)
            index = direction ? (s[j] < s[index] ? j : index) : (s[j] > s[index] ? j : index);

        //swap
        if ( i != index) {
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
        }

    };
}

/**
 * Selection Sort in ascending order
 * O(n^2)
 *
 * @param s: addr of int[], and updates the input in place. Waits NULL at the end of array so
 * it can calculate min values. Use calloc() and memcpy().
 */
void sort (int *s) {              //todo: add descending flavor
    int minIndex, tmp;

    int i = 0;
    do {
        minIndex = i;

        //find min in the remaining
        int j = i;
        do {
            minIndex = s[j] < s[minIndex] ? j : minIndex;
            j++;
        } while(s[j]);

        //swap
        if ( i != minIndex) {
            tmp = s[minIndex];
            s[minIndex] = s[i];
            s[i] = tmp;
        }

        i++;
    } while(s[i]);
}
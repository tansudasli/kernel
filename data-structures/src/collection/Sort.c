#include <stdio.h>


/**
 * Selection Sort in ascending order
 * O(n^2)
 *
 * @param s: addr of int[], and updates the input in place
 * @param length: size of s
 */
void sort2 (int *s, int length) {
    int minIndex, tmp;

    for (int i = 0; i < length; i++) {
        minIndex = i;

        //find min in the remaining
        for (int j = i + 1; j < length ; j++)
            minIndex = s[j] < s[minIndex] ? j : minIndex;

        //swap
        if ( i != minIndex) {
            tmp = s[minIndex];
            s[minIndex] = s[i];
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
void sort (int *s) {
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
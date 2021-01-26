
#include "../header/Sort.h"


/**
 * Selection Sort
 * O(n^2), in-place O(n), not data-sensitive, unstable,
 *
 * @param s: addr of int[], and updates the input in place
 * @param length: size of s
 * @param direction: DESC (default) or ASC flavor.
 */
void sort2 (int *s, int length, DIRECTION direction) {    //todo: add descending flavor
    int index, tmp;

    for (int i = 0; i < length; i++) {
        index = i;

        for (int j = i + 1; j < length; j++)
            index = (direction == ASC ? (s[j] < s[index] ? j : index) :
                                        (s[j] > s[index] ? j : index));

        //swap
        if ( i != index) {
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
        }

    };
}

/**
 * Selection Sort
 * O(n^2), in-place O(n), not data-sensitive, unstable,
 *
 * @param s: addr of int[], and updates the input in place. Waits NULL at the end of array so
 * it can calculate min values. Use calloc() and memcpy().
 * @param direction: DESC (default) or ASC flavor.
 */
void sort1 (int *s, DIRECTION direction) {
    int index, tmp;

    int i = 0;
    do {
        index = i;

        //find min in the remaining
        int j = i;
        do {
            index = (direction == ASC ? (s[j] < s[index] ? j : index) :
                                        (s[j] > s[index] ? j : index));
            j++;
        } while(s[j]);

        //swap
        if ( i != index) {
            tmp = s[index];
            s[index] = s[i];
            s[i] = tmp;
        }

        i++;
    } while(s[i]);
}

/**
 * Bubble Sort
 * O(n^2), in-place O(n), data-sensitive O(n) or O(n^2), unstable,
 *
 * @param s: addr of int[], and updates the input in place. Waits NULL at the end of array so
 * it can calculate min values. Use calloc() and memcpy().
 * @param direction: DESC (default) or ASC flavor.
 */
void sort3 (int *s, DIRECTION direction) {

}
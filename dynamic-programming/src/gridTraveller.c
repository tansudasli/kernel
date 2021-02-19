#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//O(2^m+n)
unsigned long gridTraveller(int m, int n) {

    if (m == 0 || n == 0) return 0;
    if (m == 1 && n == 1) return 1;
//    if ((m == 1 && n == 2) || (m == 2 && n == 1)) return 1;

    return gridTraveller(m-1, n) + gridTraveller(m, n-1); //down \\right
}

//O(m*n)
unsigned long gridTraveller2(int m, int n, unsigned long *memo) {

    //todo: creates collusion
    //We need a better key like k = m,n. Or we need a better hashing
    int hash = m * n;

    printf("%d x %d = %d\n", m, n, hash);

    //memoization
    if (hash-1 > 0)
        if (memo[hash-1] != 0) return memo[hash-1];

    if (m == 0 || n == 0) return 0;
    if (m == 1 && n == 1) return 1;

    unsigned long result = gridTraveller2(m-1, n, memo) + gridTraveller2(m, n-1, memo); //down \\right

    //save
    memo[hash-1] = result;

    return result;
}

//gcc -o out/gridTraveller src/gridTraveller.c  && out/gridTraveller 3 3
int main(int argc, char const *argv[]) {

    //only down and right moves are ok. up, left, cross movements are not valid.

    //m x n grid
    long m = argc > 1 ? atoi(argv[1]) : 3;
    long n = argc > 1 ? atoi(argv[2]) : 3;

    unsigned long *memoization = (unsigned long *) calloc(m * n, sizeof(unsigned long));

    unsigned long result = gridTraveller2(m, n, memoization);

    printf("%lu", result);

    //debug
    printf("\n------------\n");
    for (int i = 0; i < m * n; i++)
        printf("%lu ", *(memoization+i));

    return 0;
}
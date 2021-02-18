#include <stdio.h>
#include <stdlib.h>

//O(2^m+n)
unsigned long gridTraveller(int m, int n) {

    if (m == 0 || n == 0) return 0;
    if (m == 1 && n == 1) return 1;
    if ((m == 1 && n == 2) || (m == 2 && n == 1)) return 1;

    return gridTraveller(m-1, n) + gridTraveller(m, n-1); //down \\right
}

//gcc -o out/gridTraveller src/gridTraveller.c  && out/gridTraveller 3 3
int main(int argc, char const *argv[]) {

    //only down and right moves are ok. up, left, cross movements are not valid.

    //m x n grid
    long m = argc > 1 ? atoi(argv[1]) : 3;
    long n = argc > 1 ? atoi(argv[2]) : 3;

    unsigned long result = gridTraveller(m, n);

    printf("%lu", result);

    return 0;
}
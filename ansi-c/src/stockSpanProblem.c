#include <stdio.h>

//  gcc src/stockSpanProblem.c  -o out/stockSpanProblem  && out/stockSpanProblem
int main(int argc, char **argv) {
    //O(n^2)

//    int stocks[] = {100, 80, 60, 70, 60, 75, 85};
    int stocks[] = { 10, 4, 5, 90, 120, 80 };
    int len = sizeof(stocks)/sizeof(stocks[0]);

    //print originals
    for (int i = 0; i < len; i++)
        printf("%d ", stocks[i]);

    //
    int stockSpan[len];
    for (int i = 0; i < len; ++i) {

        stockSpan[i] = 1;
        for (int j = i - 1; j >= 0 && (stocks[i] > stocks[j]) ; j--)
            stockSpan[i]++;
    }

    printf("\n");

    for (int i = 0; i < len; i++)
        printf("%d ", stockSpan[i]);

    return 0;
}
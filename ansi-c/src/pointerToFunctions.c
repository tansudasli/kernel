#include <stdio.h>

int sum(int a, int b) {

    return a + b;
}

//gcc -o out/pointerToFunctions src/pointerToFunctions.c  && out/pointerToFunctions
int main(int argc, char *argv[]) {

    //define and init
    //syntax is critical
    int (*pFunction) (int, int) = sum;

    int r = pFunction(5, 7);

    printf("%d", r);

    return 0;
}


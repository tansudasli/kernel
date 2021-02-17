#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fibonacci(int n) {

    if (n <= 2) return 1;  //base

    return fibonacci(n-1) + fibonacci(n-2);
}

//gcc -o out/fibonacci src/fibonacci.c  && out/fibonacci 6
int main(int argc, char const *argv[]) {

    int n = (argc > 1 ? atoi(argv[1]) : 5);

    printf("fibonacci of %d = %d\n", n, fibonacci(n));
    printf("fibonacci of %d = %d", 10, fibonacci(10));

    return 0;
}


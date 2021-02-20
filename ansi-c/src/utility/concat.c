#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

int numDigits(long long v) {

    if (v < 0) return 0;
    if (v < 10) return 1;

    return 1 + numDigits(v / 10);

}

long long concatInteger(long long a, long long b) {

    char *s1 = (char *) calloc(numDigits(a) + numDigits(b), sizeof(char));
    char *s2 = (char *) calloc(numDigits(b), sizeof(char));

    sprintf(s1, "%lld", a);
    sprintf(s2, "%lld", b);

    strcat(s1, s2);
    char *eptr;

    return strtoll(s1, &eptr, 10);
}


//gcc -o out/concat src/utility/concat.c  && out/concat  123456 7000
int main(int argc, char **argv) {

    assert(numDigits(10008) == 5);
    assert(numDigits(133333335) == 9);
    assert(numDigits(1004413) == 7);

    assert(concatInteger(100, 300) == 100300);


    printf("%lld\n", concatInteger(argc > 1 ? atoll(argv[1]) : 444,
                                   argc > 1 ? atoll(argv[2]) : 555));


    return 0;
}
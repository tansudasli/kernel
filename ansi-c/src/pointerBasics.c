#include <stdio.h>

int main(int argc, char **argv) {
    /** In int/char type variables,
     *      - pointer waits an address. & do the job
     *      - indirection of pointer contains the value.
     */

    //integer
    int num = 5;           //assign number or *pointer
    int *numPtr = &num;    //waits a pointer of integer == address
    int num2 = *numPtr;    //*pointer = indirection of pointer

    printf("num=%d, address of num=%p\n", num, &num);
    printf("numPtr=%p, value inside ptr=%d\n\n", numPtr, *numPtr);

    //char
    char ch = 'H';
    char *chPtr = &ch;
    char *k = "abc"; //valid

    printf("ch=%c, address of ch=%p\n", ch, &ch);
    printf("chPtr=%p, value inside ptr=%c\n\n", chPtr, *chPtr);

    /**
     * In arrays of int/char, array is the address of itself
     * But, int[] not like char[]. You have to use m[0] or *m to access the value.
     *
     * The difference b/w int[]|char[] and char*|int* is pointing strategy
     *
     * In char[], you have chance to use %c and %s . In int[] , you can only use %d, So
     * There is one diff. while accessing to value. %s waits char*, while %c waits char.
     *
     * Array is pointer and has value, But pointer has addr, not value. Value' addr is somewhere in memory.
     */

    //array
    int m[] = {1,2,3,4,5};
    int *mPtr = m;    //m is same as &d. cause it is array!!!
    //int *z = {1,2,3,4,5}; //not valid
    //int *ho = 12345; //not valid and not meaningful as char* !!!


    printf("%d %d %p == %p == %p\n", m[0], *m, &m, m, &m[0]);       //array is the address of itself
    printf("%d %p != %p\n\n", *mPtr, &mPtr, mPtr);

    //
    char msg[] = "Hello";
    char *msg2 = "Mello";

    printf("%c %c %s %p == %p\n", *(msg+1), msg[0], msg, &msg, msg);    //array is the address of itself
    printf("%c %s %p != %p\n", *msg2, msg2, &msg2, msg2); //but, Mello's addr. is different from msg2's addr
                                                          //here, is also *msg2 and msg2 usage diff. %c waits char, %s waits char*

    /**
     * char/int and arrays of (int/char..) act different !!
     */

    return 0;
}
#include <stdio.h>

//#define (you may still reassign :)) or const (real constant). 
#define TAX_STANDART 0.18
const double TAX_LUX_CONSUPTION=0.20;

/**
 * Build, then Run w/
 *    gcc -o out/variables src/variables.c && ./out/variables 
 */
int main(int argc, char const *argv[])
{
    /* code */
    printf("TAX_STANDART = %f \n", TAX_STANDART);      //0.180000, 8 precision digit
    printf("TAX_STANDART = %.3f \n", TAX_STANDART);    //0.180
    printf("TAX_LUX_CONSUPTION = %.3f \n", TAX_LUX_CONSUPTION);    //0.200

    //w/o casting it gives crazy something :)
    printf("TAX_STANDART = %d \n", (int)TAX_STANDART); //0


    return 0;
}

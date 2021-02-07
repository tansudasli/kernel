#include <stdio.h>

#define SIZE 3

char *words[SIZE];   //hold some initial data  w0 w1 w2  => char[][]

void initialize() {
    words[0] = "ali";
    words[1] = "veli";
    words[2] = "deli";

    for (int j = 0; j < SIZE; j++)
        printf("%s\t", words[j]);

    printf("\n");
}

//gcc -o out/pointerIndirectionString src/pointerIndirectionString.c  && out/pointerIndirectionString
int main(int argc, char **argv) {

    char ch = 'c';   //value
    char *pc;        //pointer                 char pc[]                  or  a word (n length but still 1 word)
    char **ppc;      //pointer to pointer      char *pc[] or  char pc[][] or  a kind of word list

    initialize();

    //accessing w/ arrays
    ppc = words;  //words is an array so it is an address also

    printf("words\t\t\t ppc\t\t\t pc\n");
    for (int j = 0; j < SIZE; j++) {
        pc = *ppc;

        printf("%s(%p)\t %s(%p)\t %s(%p)\n",words[j], &words[j]
                                  ,*ppc    , ppc
                                  ,pc      , pc);
    // we can also treat **ppc as an array. ppc[j] also works !!
        ppc++;
    }


    //accessing w/ pointers
    ppc = words;
    for (int j = 0; j < SIZE; j++) {
        pc = *ppc;

        //1st way -
//        while ( *pc != 0) {
//            printf("%c\t", *pc);
//            pc++;
//        }

        //2nd way
        while ( **ppc != 0) {
            printf("%c\t", **ppc);
            (*ppc)++;
        }

        printf("\n");

        ppc++;
    }

    return 0;
}
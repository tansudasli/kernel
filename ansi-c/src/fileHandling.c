#include <stdio.h>

#define FILE_NAME "resources/dummy.txt"

void readLines() {
  FILE *file = fopen(FILE_NAME, "r");

  if (file != NULL) {
      printf("x");

  } else {
      printf( "File %s cannot be opened!", FILE_NAME );
  }

}

int main(int argc, char const *argv[]) {

    readLines();

    return 0;

}


#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 255
#define MAX_ROW 3
#define FILE_NAME "resources/dummy.txt"

/**
 * Read file
 *
 * @return -1 if error, or line count in read file
 */
int readLines() {

    int lineCount = 0;
    char line[MAX_LINE];

    FILE *file = fopen(FILE_NAME, "r");

    if (file != NULL) {

        printf("line \tcontent \n");
        while (fgets(line, MAX_LINE, file) != 0)
            printf("%d \t%s", ++lineCount, line);       // fputs(line, stdout);

        fclose(file);
    } else {
        printf( "File %s cannot be opened!", FILE_NAME );

        return -1;
    }

    return lineCount;
}

/**
 * Append new lines to file
 *
 * @return -1 if error, or line count appended to file
 */
int appendLines() {

    char lines[MAX_ROW][MAX_LINE] = {
            {"We are what we repeatedly do. Excellence, then, is not an act, but a habit.\n"},
            {"The whole is more than the sum of its parts.\n"},
            {"Man is by nature a political animal.\n"}
    };

    FILE *file = fopen(FILE_NAME, "a+");

    if (file != NULL) {
        for (int i = 0; i < ROW; i++)
            fputs(lines[i], file);

        fclose(file);
    } else {
        printf( "File %s cannot be opened!", FILE_NAME );

        return -1;
    }

    return MAX_ROW;
}

int main(int argc, char const *argv[]) {

    readLines();
    appendLines();
    readLines();

    return 0;

}


#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in the file

int main() {
    FILE *file1, *file2;
    char line[MAX_LINE_LENGTH];

    // Open test1.txt for reading
    file1 = fopen("test1.txt", "r");
    if (file1 == NULL) {
        printf("Error opening test1.txt for reading.\n");
        return 1;
    }

    // Open test2.txt for writing
    file2 = fopen("test2.txt", "w");
    if (file2 == NULL) {
        printf("Error opening test2.txt for writing.\n");
        fclose(file1);
        return 1;
    }

    // Move contents of test1.txt to test2.txt
    while (fgets(line, MAX_LINE_LENGTH, file1) != NULL) {
        fputs(line, file2);
    }

    // Close files
    fclose(file1);
    fclose(file2);

    // Clear test1.txt
    file1 = fopen("test1.txt", "w");
    if (file1 == NULL) {
        printf("Error opening test1.txt for clearing.\n");
        return 1;
    }
    fclose(file1);

    printf("Contents moved from test1.txt to test2.txt successfully.\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* file = fopen("LOTR.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char * word = (char *)malloc(100*sizeof(char));
    int count = 0;

    while (fscanf(file, "%s", word) == 1) {
        // Convert word to lowercase for case-insensitive comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        // Check if the word is "hobbit"
        if (strstr(word, "hobbit")) {
            count++;
        }
    }

    fclose(file);

    printf("The word 'hobbit' appears %d times in 'LOTR.txt'.\n", count);
    free(word);
    return 0;
}
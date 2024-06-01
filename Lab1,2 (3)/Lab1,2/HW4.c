#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "The quick brown fox";
    char delim[] = " ";  // space character as delimiter
    char *token;

    // strtok modifies the original string, so we make a copy
    char str_copy[100];
    strcpy(str_copy, str);

    // Get the first token
    token = strtok(str_copy, delim);

    // Iterate through the remaining tokens
    while (token != NULL) {
        printf("Token: %s\n", token);
        
        // Get the next token
        token = strtok("NULL", delim);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Reading input of unknown length of strings
// Running until recieved "words" amount of words.
char *inputString(size_t words) {

    size_t size = 10; // Start with some initial size
    char *str = (char *)malloc(size * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    size_t len = 0;
    size_t wordCount = 0;
    int ch;
    while (wordCount < words) {
        ch = getchar();
        if (ch == ' ' || ch == '\n') {
            if (len > 0) {
                str[len++] = '\0'; // Null-terminate the word
                wordCount++;
                len = 0; // Reset the length for the next word
            }
        } else {
            str[len++] = ch;
            if (len == size) { //Increasing memory allocation if reached the previous one
                size *= 2;
                str = (char *)realloc(str, size * sizeof(char));
                if (str == NULL) {
                    printf("Memory reallocation failed\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    str[len] = '\0'; // Null-terminate the last word
    return str;
}

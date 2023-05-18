#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "Dehli is capital of India.";
    char pattern[] = "capital";
    int string_len = strlen(string);
    int pattern_len = strlen(pattern);

    for (int i = 0; i < string_len - pattern_len + 1; i++) {
        int j;
        for (j = 0; j < pattern_len; j++) {
            if (string[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == pattern_len) {
            printf("Pattern found at position %d.\n", i);
        }
    }

    return 0;
}


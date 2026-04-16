

/* Write a program to print a histogram of different characters in 
its input. */

#include <stdio.h>

/* Maximum number of different characters in standard ASCII */
#define MAX_CHARS 256

int main() {
    int c, i, j;
    int counts[MAX_CHARS];

    /* Initialize all character counts to zero */
    for (i = 0; i < MAX_CHARS; i++) {
        counts[i] = 0;
    }

    /* Read characters until end of input */
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < MAX_CHARS) {
            counts[c]++;
        }
    }

    printf("\nCharacter Frequency Histogram:\n");

    /* Loop through the array and print a bar for characters that appeared */
    for (i = 0; i < MAX_CHARS; i++) {
        if (counts[i] > 0) {
            /* Format the label for readability */
            if (i == ' ') {
                printf("' ' : ");
            } else if (i == '\n') {
                printf("'\\n': ");
            } else if (i == '\t') {
                printf("'\\t': ");
            } else if (i >= 32 && i <= 126) {
                printf("'%c' : ", i);
            } else {
                printf("0x%02X: ", i); /* Hex for non-printables */
            }

            /* Print a bar of '#' characters representing the frequency */
            for (j = 0; j < counts[i]; j++) {
                putchar('#');
            }
            printf(" (%d)\n", counts[i]);
        }
    }

    return 0;
}
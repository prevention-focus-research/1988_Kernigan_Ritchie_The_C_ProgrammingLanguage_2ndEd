/* Write a program to print a histogram of the lengths of words in 
its input. It is easy to draw a histogram with the bars horizontal;  
vertical orientation is more challenging*/

/*VERTICAL VERSION*/

/* Program 2: Vertical histogram of word lengths */
/* ANSI C - K&R style */

#include <stdio.h>

#define MAX_WORD_LEN 20   /* words longer than this are capped */

int main(void)
{
    int c;
    int len = 0;
    int hist[MAX_WORD_LEN + 1] = {0};
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (len > 0) {
                if (len > MAX_WORD_LEN)
                    len = MAX_WORD_LEN;
                hist[len]++;
                len = 0;
            }
        } else {
            len++;
        }
    }
    
    /* last word */
    if (len > 0) {
        if (len > MAX_WORD_LEN)
            len = MAX_WORD_LEN;
        hist[len]++;
    }
    
    /* Find maximum frequency for vertical scale */
    int max_freq = 0;
    for (int i = 1; i <= MAX_WORD_LEN; i++) {
        if (hist[i] > max_freq)
            max_freq = hist[i];
    }
    
    /* Print vertical histogram */
    printf("Vertical word length histogram:\n\n");
    
    /* Print bars from top to bottom */
    for (int row = max_freq; row > 0; row--) {
        for (int i = 1; i <= MAX_WORD_LEN; i++) {
            if (hist[i] >= row)
                putchar('*');
            else
                putchar(' ');
            putchar(' ');   /* spacing between columns */
        }
        putchar('\n');
    }
    
    /* Print x-axis (word lengths) */
    for (int i = 1; i <= MAX_WORD_LEN; i++)
        printf("%-2d", i);   /* two characters per column */
    putchar('\n');
    
    return 0;
}
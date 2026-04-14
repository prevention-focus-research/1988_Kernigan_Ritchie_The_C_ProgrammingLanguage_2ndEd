/* Write a program to print a histogram of the lengths of words in 
its input. It is easy to draw a histogram with the bars horizontal;  
vertical orientation is more challenging*/

#include <stdio.h>

#define IN  1   /* inside a word*/ 
#define OUT 0   /* outside a word*/

int main()
{
    int c, i, wlength, state;

    state = OUT;
    wlength = 0;
    while ((c = getchar()) != EOF) {
        ++wlength;
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("%d: ", (wlength-1));
            for (i = 0; i < (wlength-1); ++i) {
                printf("*");
            }
            printf("\n");
            state = OUT;
            wlength = 0;
        }            
        else if (state = OUT) {
            putchar(c);
            state = IN;
        }
    }
    return 0;    
}
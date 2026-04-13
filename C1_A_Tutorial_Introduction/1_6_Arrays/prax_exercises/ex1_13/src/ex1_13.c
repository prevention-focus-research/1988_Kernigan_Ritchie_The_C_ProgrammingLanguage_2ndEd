/* Write a program to print a histogram of the lengths of words in 
its input. It is easy to draw a histogram with the bars horizontal;  
vertical orientation is more challenging*/

#include <stdio.h>

#define IN  1   /* inside a word*/ 
#define OUT 0   /* outside a word*/

/* count lines, words, and characters in input */

int main()
{
    int c, wlength, state;

    state = OUT;
    wlength = 0;
    while ((c = getchar()) != EOF) {
                
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state = OUT) {
            state = IN;
            ++wlength;
        }
    }
    return 0;    
}
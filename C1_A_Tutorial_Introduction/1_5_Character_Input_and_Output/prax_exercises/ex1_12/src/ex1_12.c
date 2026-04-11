/* Write a program that prints its input one word per line*/

#include <stdio.h>

#define IN  1   /* inside a word*/ 
#define OUT 0   /* outside a word*/

/* count lines, words, and characters in input */

int main()
{
    int c;
 
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
            putchar(c);
        }            
        else {
            putchar(c);
        }
    } 
    return 0;
}
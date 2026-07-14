/* Write a program `detab` that replaces tabs in the input with the 
proper number of blanks to space to the next tab stop. Assume a fixed 
set of tab stops, say every *n* columns. Should *n* be a variable or 
a symbolic parameter? */

#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int max);
int mod(int dividend, int divisor);

int main() {
    
    int len, remainder;                 /* current line length */
    int max;                            /* maximum length seetn so far */
    char line[MAXLINE];                 /* current input line*/
    char longest[MAXLINE];              /* longest line saved here */
    

    remainder =  mod(7,2);
    printf("The remainder of dividing 7 by 2 is %d.", remainder);
    return 0;
}

int mod(int dividend, int divisor) 
{
    int i;

    i = 1;
    if (divisor <= dividend) {
        while (divisor <= dividend) {
            dividend = dividend - divisor;
            ++i;
            divisor = divisor*i;
        }
    }
    return dividend;
}

int my_getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

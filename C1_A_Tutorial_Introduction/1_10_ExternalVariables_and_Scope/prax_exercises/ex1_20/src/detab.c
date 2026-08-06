/* Write a program `detab` that replaces tabs in the input with the 
proper number of blanks to space to the next tab stop. Assume a fixed 
set of tab stops, say every *n* columns. Should *n* be a variable or 
a symbolic parameter? 

- Tab stops occur at fixed, regular column intervals — for example, every 8 columns (columns 1, 9, 17, 25, ...). You get to pick the interval, call it `n`.
- When the program encounters a tab character (`'\t'`) in the input, it should output enough space characters to advance the current column position to the next tab stop — *not* a fixed number of spaces every time. The number of spaces needed depends on where the cursor currently is on the line.
  - Example: if tab stops are every 8 columns and a tab occurs when the cursor is at column 3, output 5 spaces (to reach column 8/9, depending on how you index). If a tab occurs at column 9, output 8 spaces (to reach the next stop, column 17).
- All non-tab characters should be copied to the output unchanged.
- You'll need to track the current column position as you read through the input, resetting it appropriately when you hit a newline.

*/
#include <stdio.h>

#define MAXLINE 1000

int my_getline(char line[], int max);
int modulus(int dividend, int divisor);
void copy_detab(char to[], char from[]);

int main() {
    
    int len, remainder, n, ntabs, tabpos;   /* current line length */
    int max;                                /* maximum length seetn so far */
    char line[MAXLINE];                     /* current input line*/
    char longest[MAXLINE];                  /* longest line saved here */
    
    // remainder =  modulus(7,2);
    // printf("The remainder of dividing 7 by 2 is %d.", remainder);
    // return 0;

    while ((len = my_getline(line, max)) > 0) {
        for (int i=0; i<len; ++i) {
            if (i > n) {
                
            }
            if (line[i] == '\t') {
                
            }
        }
    }






}

int modulus(int dividend, int divisor) 
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

void copy_detab(char to[], char from[]) {
    
    int i=0;
    
    while((to[i] = from[i]) != '\0');
        ++i;
}
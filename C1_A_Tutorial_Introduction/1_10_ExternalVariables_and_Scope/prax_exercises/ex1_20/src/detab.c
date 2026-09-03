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
    
    int len, remainder;   /* current line length */
    int max;                                /* maximum length seetn so far */
    char line[MAXLINE];                     /* current input line*/
    char tabline[MAXLINE];                  /* tabline line saved here */
    
/*     
    remainder =  modulus(7,2);
    printf("The remainder of dividing 7 by 2 is %d.", remainder);
    return 0;
 */       
    
    int i, currentpos, ntabs_chars, nexttabpos=0;
    int line_cursor, num_spaces_to_add, space_cursor, tab_cursor, next_tab_pos, num_tab_stops_crossed=0, n=4;

    next_tab_pos = num_tab_stops_crossed*n + n;

    while ((len = my_getline(line, max)) > 0) {
        for (i = 0; i < len; ++i) {
            if (i > next_tab_pos) {
                ++num_tab_stops_crossed;                
                next_tab_pos = num_tab_stops_crossed*n + n;
            }
            if (line[i] == '\t') {
                line_cursor = i;
                num_spaces_to_add = next_tab_pos - line_cursor;
                for (space_cursor = 0; space_cursor < num_spaces_to_add; ++space_cursor) {
                    tabline[line_cursor + space_cursor] = ' ';
                }
                ++i;
                ++ntabs_chars;
                tab_cursor=line_cursor + space_cursor;
            } else {
                if (ntabs_chars > 0) {
                    tabline[tab_cursor] = line[i];
                } else {
                    tabline[i] = line[i];
                }
            }
        }
    }
    printf("original line: %s\n", line);
    printf("%s", tabline);
    return 0;
}

int modulus(int dividend, int divisor) 
{
    int i;

    i = 1;
    while (divisor <= dividend) {
        dividend = dividend - divisor;
        ++i;
        divisor = divisor*i;
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
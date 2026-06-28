

/* Exercise 1-19: Write a function `reverse(s)` that reverses the character 
string `s`. Use it to write a program that reverses its input a line at a 
time. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse_copy(char to[], char from[], int len);

int main(void) {
    char line[MAXLINE];
    char reversed[MAXLINE];
    int len, c, clen;

    /* Read each line from standard input */
    while ((len = get_line(line, MAXLINE)) > 0) {
        /* Clean the line and get its new length */
        // HERE -- p. 30+!
        reverse_copy(line, reversed, len);
    }

    return 0;
}

/* get_line: read a line into s, return length (includes trailing newline) */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse_copy(char original[], char reversed[], int len)
{
    int i;

    i = 0;
    while (original[i] != '\0') {
        reversed[len-i] = original[i-1];
        ++i;
    }
        
}
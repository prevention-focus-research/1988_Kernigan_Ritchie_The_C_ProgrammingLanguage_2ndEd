

/* Exercise 1-16: Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line length */
#define LIMIT 80        /* Threshold for printing */

int getline(char line[], int maxline);

int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > LIMIT) {
            printf("%s", line);
        }
    }

    return 0;
}

/* Function to read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i, nt, nb;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    if (c == '\t' || c == '\b') {
       s[i] = s[i-1]; 
       i--;
    }
    s[i] = '\0';
    return i;
}
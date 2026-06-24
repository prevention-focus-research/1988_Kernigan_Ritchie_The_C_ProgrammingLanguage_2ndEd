

/* Exercise 1-19: Write a function `reverse(s)` that reverses the character 
string `s`. Use it to write a program that reverses its input a line at a 
time. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int remove_trailing(char s[], int len);

int main(void) {
    char line[MAXLINE];
    char reversed[MAXLINE];
    int len;

    /* Read each line from standard input */
    while ((len = get_line(line, MAXLINE)) > 0) {
        /* Clean the line and get its new length */
        len = remove_trailing(line, len);
        
        /* If the line is not entirely blank, print it */
        if (len > 0) {
            printf("%s", line);
        }
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

/* remove_trailing: removes trailing blanks and tabs; adjusts newline if present */
int remove_trailing(char s[], int len) {
    int i = len - 1;

    /* Move backward past the newline character if it exists */
    if (i >= 0 && s[i] == '\n') {
        i--;
    }

    /* Keep moving backward past any spaces or tabs */
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        i--;
    }

    /* If we didn't back up to the very beginning, we preserve the newline */
    if (i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    } else {
        /* The line is entirely blank */
        s[0] = '\0';
    }

    return i;
}

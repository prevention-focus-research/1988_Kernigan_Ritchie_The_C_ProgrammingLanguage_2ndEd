

/* Exercise 1-19: Write a function `reverse(s)` that reverses the character 
string `s`. Use it to write a program that reverses its input a line at a 
time. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
/* Added 'len' as a parameter to avoid calling get_line twice */
void reverse_copy(char to[], char from[], int len);

int main(void) {
    char line[MAXLINE];
    char reversed[MAXLINE];
    int len;

    /* Read each line from standard input */
    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse_copy(reversed, line, len); /* Adjusted argument order to match (to, from) */
        printf("The reversed line is: %s", reversed);
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

/* Copies 'from' into 'to' in reverse order, preserving trailing newline */
void reverse_copy(char to[], char from[], int len)
{
    int i;
    int src_end = len - 1; /* index of the last character before '\0' */
    int dest_idx = 0;

    /* If the line ends with a newline, we want to leave it for the end */
    if (src_end >= 0 && from[src_end] == '\n') {
        src_end--; 
    }

    /* Copy characters backwards from the end of 'from' to the start of 'to' */
    for (i = src_end; i >= 0; i--) {
        to[dest_idx] = from[i];
        dest_idx++;
    }

    /* Put the newline back at the end if the original string had one */
    if (len > 0 && from[len - 1] == '\n') {
        to[dest_idx] = '\n';
        dest_idx++;
    }

    /* Always properly null-terminate the new string */
    to[dest_idx] = '\0';    
}
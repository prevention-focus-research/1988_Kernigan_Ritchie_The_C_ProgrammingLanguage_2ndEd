/* 1. remove trailing blanks from each line of input.*/

#include <stdio.h>

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* getline: read a line into s, return length, removing trailing blanks and tabs */
int getline_no_tb_tt(char s[], int lim)
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t') {
            putchar(c);
        }
    }
    return 0;
}





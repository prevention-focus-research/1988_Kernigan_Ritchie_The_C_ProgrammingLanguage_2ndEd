/* 1. remove trailing blanks from each line of input.*/

#include <stdio.h>

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int is_non_blank_line(char line[], int max);
int rm_tr_blank_tabs(char old[], char new[], int max);

/* remove trailing blanks and tabs from the line */
int rm_tr_blank_tabs(char o[], char n[], int lim) {

    int i;

    while (o[(lim-1)-i] == ' ' || o[(lim-1)-i] == '\t') {
        // 
    }
}

/* check if the entire line is composed of blanks or tabs. */
int is_non_blank_line(char s[], int lim)
{
    int nb, i;

    i = 0;
    while (s[i] != '\0')
        if (s[i] == ' ' || s[i] == '\t') {
            ++nb;
        }
        ++i;
    if (!nb == (lim-1))  return 0;    
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
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





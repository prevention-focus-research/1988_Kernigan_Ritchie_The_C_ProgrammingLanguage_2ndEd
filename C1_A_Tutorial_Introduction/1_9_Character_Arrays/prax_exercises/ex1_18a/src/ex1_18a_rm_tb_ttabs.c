/* 1. remove trailing blanks from each line of input.*/

#include <stdio.h>

#define MAXLINE 1000        /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int copy_substring(char to[], char from[]);
int get_line_length(char line[]);
int is_non_blank_line(char line[], int max);
int rm_tr_blank_tabs(char old[], char new[]);

/* remove trailing blanks and tabs from the line */
int rm_tr_blank_tabs(char o[], char n[]) {

    /* pseudo code: 
        if the line length is > 0:
            if the last character is a blank or tab, copy the line until the character preceding the last one.
                repeat until there are no more characters left, or the last character is neither a blank nor a tab.
        else, return the line. */

    int line_len, i;

    line_len = get_line_length(o);
    while (line_len > 0 && (o[line_len-1] == ' ' || o[line_len-1] =='\t')) {
        o = copy_substring(o,n);
        line_len = get_line_length(o);
    }   
    return o; 
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

/* get line length */
int get_line_length(char line[])
{
    int i;

    i = 0;
    while (line[i] != '\0')
        ++i;
    return i;
}

/* return a substring */
int copy_substring(char from[], char to[])
{
    int i, j, len;
    i=0;
    while (from[i] != '\0') ++i;

    len = i-1;
    for (j=0; j < len; ++j)
        to[j] = from[j];
    to[j] = '\0';
    return to;
}


int main() 
{
    int len;                /* current line length */
    // int max;                /* maximum length seetn so far*/
    char line[MAXLINE];         /* current input line*/
    char longest[MAXLINE];      /* longest line saved here */

    // max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        // if (len > max) {
            // max = len;
        copy(longest, line);
        // }
    // if (max > 0)    /* there was a line */
    //     printf("The longest line is %d characters long.", max);
    //     printf("\n");
    //     printf("The line is: %s", longest);
    // rm_tr_blank_tabs(char o[], char n[])
        
    return 0;
};







/* Exercise 1-19: Write a function `reverse(s)` that reverses the character 
string `s`. Use it to write a program that reverses its input a line at a 
time. */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

/* Function to reverse a character string s in-place */
void reverse(char s[]) {
    int i, j;
    char temp;

    /* Manually find the length of the string to avoid strlen() */
    for (j = 0; s[j] != '\0'; j++)
        ;
    j--; /* Move back from the null terminator */

    /* Keep the newline character (\n) at the end of the line if it exists */
    if (j >= 0 && s[j] == '\n') {
        j--;
    }

    /* Swap characters from both ends moving inward */
    for (i = 0; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* Helper function to read a line into s, return length */
int my_getline(char s[], int lim) {
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

int main(void) {
    char line[MAXLINE];

    /* Read a line at a time, reverse it, and print it */
    while (my_getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}
/* Write a program to copy its input to its output, replacing each string of 
or more blanks by a single blank*/

#include <stdio.h>

/* Copy input to output, replacing strings of blanks with a single blank */
int main() {
    int c;
    int last_char_was_blank = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!last_char_was_blank) {
                putchar(c);
                last_char_was_blank = 1;
            }
        } else {
            putchar(c);
            last_char_was_blank = 0;
        }
    }

    return 0;
}
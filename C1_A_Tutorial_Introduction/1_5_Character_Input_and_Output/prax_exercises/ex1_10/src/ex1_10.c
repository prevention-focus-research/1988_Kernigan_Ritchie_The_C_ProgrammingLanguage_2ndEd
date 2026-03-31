/* Write a program to copy its input to its output, replacing 
each tab by `\t`, each backspace by `\b` and each backslash by `\\`. 
This makes tabs and backspaces visible in an unambiguous way.*/

#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            /* Replace tab with \t */
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            /* Replace backspace with \b */
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            /* Replace backslash with \\ */
            putchar('\\');
            putchar('\\');
        } else {
            /* Output all other characters as-is */
            putchar(c);
        }
    }
    return 0;
}

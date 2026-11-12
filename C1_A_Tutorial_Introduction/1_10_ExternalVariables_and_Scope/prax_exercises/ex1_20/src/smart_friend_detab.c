/* 


How It Works

• Column Tracking: The col variable tracks the current horizontal position using a 
0-based index, resetting to 0 whenever a newline (\n) is encountered.

• Modulo Arithmetic: When a tab (\t) is read, col % TABSTOP determines how many 
columns past the previous tab stop the cursor currently sits. Subtracting that remainder from TABSTOP gives the exact number of spaces needed to reach the next boundary.

• Standard I/O: The program reads from standard input (stdin) and writes to standard 
output (stdout), allowing you to use shell redirection (e.g., ./detab < input.txt > output.txt).

Should n Be a Variable or a Symbolic Parameter?

In the context of Chapter 1 of K&R C, n should be a symbolic parameter (#define TABSTOP 8), 
though a variable becomes preferable as requirements evolve.

• Why a Symbolic Parameter is Best Here:
	
    • Readability & Maintainability: Defining #define TABSTOP 8 eliminates "magic numbers" in the 
    code and lets you change the tab width in one place before compiling.
	
    • Zero Runtime Overhead: The preprocessor substitutes the literal value 8 directly into 
    the source code before compilation, saving memory and avoiding variable lookups.
	
    • Historical Context: In K&R Chapter 1, symbolic constants are introduced specifically to 
    handle fixed program parameters like array sizes and tab stops before command-line arguments are covered.

• When to Use a Variable Instead:
	
    • Runtime Flexibility: If you later extend the program to accept custom tab widths from the 
    user via command-line arguments (e.g., detab -4 or detab 4), n must be stored in a int 
    variable so it can be modified while the program is running.
*/

#include <stdio.h>

#define TABSTOP 8   /* Tab stop interval (symbolic parameter) */

int main(void)
{
    int c;
    int col = 0;    /* Current 0-based column position on the line */
    int spaces;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            /* Calculate spaces needed to reach the next tab stop */
            spaces = TABSTOP - (col % TABSTOP);
            while (spaces > 0) {
                putchar(' ');
                ++col;
                --spaces;
            }
        } else if (c == '\n') {
            putchar(c);
            col = 0;    /* Reset column counter at the start of a new line */
        } else {
            putchar(c);
            ++col;
        }
    }

    return 0;
}

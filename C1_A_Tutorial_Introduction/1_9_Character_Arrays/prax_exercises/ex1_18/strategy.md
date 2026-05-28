# STRATEGY FOR EXERCISE 1-18

## EXERCISE 1-18:
Exercise 1-18: Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines.

### OBJECTIVES

1. remove trailing blanks from each line of input.

2. remove tabs from each line of input.

3. remove trailing tabs from each line of input.

4. delete entirely blank lines. 

### IMPLEMENTATION STRATEGIES FOR EACH OBJECTIVE

* objective 1: Exercises 1-8, 1-9, and 1-10 would be most relevant. 

1. remove trailing blanks from each line of input.


trailing blanks -- 



#### ex 1-8: 

```c
/* Write a program to count blanks, tabs, and newlines*/

#include <stdio.h>

int main()
{
    int c, nb, nt, nl;  /* nb = number of blanks, nt = number of tabs, nl = 
    number of new lines*/

    nb = nt = nl = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++nb;
    }
    printf("blanks: %d; tabs: %d; newlines: %d\n", nb, nt, nl);
}
```

#### ex 1-9: 

```c
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
```

#### ex 1-10:

```c
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
```
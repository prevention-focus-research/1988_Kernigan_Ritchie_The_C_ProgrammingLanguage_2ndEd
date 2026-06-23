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

the last character of a line cannot be a `'\t'` or `' '` character

>>> A trailing blank character is any invisible space, tab, or carriage return located at the very end of a line of text or string, immediately preceding a line break. These invisible characters are often overlooked but significantly impact code execution, file comparisons, and data processing

pseudo code: 

if the line length is > 0:
    if the last character is a blank or tab, copy the line until the character preceding the last one.
        repeat until there are no more characters left, or the last character is neither a blank nor a tab.


else, return the line. 

we retrieve the line -- the we do two things:

--deleteing blank lines
1. go through the line and check that at least one character is some character other than a blank or tab.
2. if it's not, we return just the null character.
--trailing blanks problem is more difficult. 

```c
int is_non_blank_line(char line[] int max);

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


void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
```


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




This error occurs because you are trying to assign an integer value directly to a pointer variable (`char *`) without converting (casting) it.

In C, a pointer is a variable that stores a **memory address**. An integer is just a data value. The compiler prevents you from accidentally setting a memory address to a random number because doing so usually leads to program crashes (like segmentation faults).

Here are the two most common reasons this happens and how to fix them.

---

### Scenario 1: Forgetting to allocate memory (or missing an ampersand)

Often, you actually intended to point to the memory address of an integer, or you accidentally used an integer variable when you meant to use a string.

**The Broken Code:**

```c
int code = 65; 
char *ptr;

ptr = code; // ERROR: Assigning the integer 65 to a pointer

```

**The Fix:**
If you want the pointer to point to the memory address where `code` is stored, use the address-of operator (`&`):

```c
int code = 65;
char *ptr;

ptr = (char *)&code; // Correct: ptr now points to the address of 'code'

```

---

### Scenario 2: Misusing functions that return integers (like `malloc` without headers)

If you are calling a function that returns an integer, but you try to assign it to a `char *`, you will get this error.

A classic example is using `malloc()` without including `<stdlib.h>`. In older ANSI C standards, if a function isn't declared before it's used, the compiler implicitly assumes it returns an `int`.

**The Broken Code:**

```c
#include <stdio.h>
// Missing #include <stdlib.h>

int main() {
    char *ptr = malloc(10); // ERROR: Compiler thinks malloc returns an int!
    return 0;
}

```

**The Fix:**
Simply include the correct header file so the compiler knows the function returns a pointer (`void *`), not an `int`:

```c
#include <stdio.h>
#include <stdlib.h> // Fixes the implicit declaration

int main() {
    char *ptr = malloc(10); // Correct
    return 0;
}

```

---

### Scenario 3: Assigning a single character incorrectly

In C, a character literal inside single quotes (like `'A'`) is treated as an integer (its ASCII value). A string literal inside double quotes (like `"A"`) is treated as a pointer (`char *`).

**The Broken Code:**

```c
char *ptr;
ptr = 'A'; // ERROR: 'A' evaluates to the integer 65

```

**The Fix:**
Use double quotes if you want it to be a string pointer:

```c
char *ptr;
ptr = "A"; // Correct: Points to the string literal "A"

```





#### PROMPT
using the ANSI C (`-std=c89`), write a program that satisfies the following statement: "Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines."

#### RESPONSE:
Here is a complete ANSI C (`-std=c89`) program that reads from standard input, strips trailing spaces and tabs from each line, and completely skips lines that become entirely empty after stripping.

To remain strictly compliant with C89, all variables are declared at the beginning of their respective blocks, and standard, widely compatible constructs are used.

```c
#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int remove_trailing(char s[], int len);

int main(void) {
    char line[MAXLINE];
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

```

### How It Works

* **`get_line`**: Safely grabs a chunk of text up to a newline character, mirroring the classic K&R style approach. It returns the total length of the string, ensuring we know exactly where to start looking backward.
* **`remove_trailing`**:
* It starts scanning from the end of the string (`len - 1`).
* It ignores the `\n` temporarily to look at the actual text characters before it.
* It loops backward as long as it encounters a space (`' '`) or a tab (`'\t'`).
* Once it hits a valid character, it appends the `\n` back right after it and terminates the string with `\0`. If it runs all the way back to index `-1`, it means the line was nothing but whitespace, so it clears the string completely.


* **`main`**: Filters out the results. If `remove_trailing` returns a length of `0`, the program silently drops the line instead of printing an empty newline.
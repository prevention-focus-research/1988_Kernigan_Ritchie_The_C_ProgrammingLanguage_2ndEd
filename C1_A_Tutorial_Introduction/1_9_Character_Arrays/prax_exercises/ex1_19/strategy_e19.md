# STRATEGY FOR EXERCISE 1-18

## EXERCISE 1-19:
Exercise 1-19: Write a function `reverse(s)` that reverses the character string `s`. Use it to write a program that reverses its input a line at a time.

There are two major logic flaws in this program, both located inside your `reverse_copy` function.

Here is a breakdown of what is going wrong and how to fix it.

---

## 1. The Core Issues

### Issue A: `reverse_copy` Calls `get_line` Again

Inside `main`, you already successfully read a line into the `line` array using `get_line(line, MAXLINE)`.

However, inside `reverse_copy`, you do this:

```c
len = get_line(original, MAXLINE);

```

Because `getchar()` advances the input stream, calling `get_line` a second time doesn't look at the data you just read—it completely overwrites the `original` array with the *next* line of input from the keyboard/file (or breaks if there isn't one).

Instead of reading input again, `reverse_copy` should simply measure the string that is already sitting in the array.

### Issue B: Hardcoded Newline Math (`len-2`)

Your math assumes every single line will end with a newline character (`\n`), which sets `tlen = len - 2`.

* If the final line of a file does not end with a newline, or if the line is completely empty, `tlen` will result in a negative index or an incorrect length calculation, leading to undefined behavior or skipped characters.

---

## 2. The Fixed Program

To fix this while keeping your approach of copying to a new buffer, you should pass the already-calculated `len` into `reverse_copy`, or manually calculate the length of `original` inside the function.

Here is the corrected program:

```c
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

```

### Summary of Fixes:

1. **Removed the duplicate input fetch:** `reverse_copy` now accepts `len` directly from `main`.
2. **Safe Newline Logic:** It checks explicitly if `from[len - 1] == '\n'` rather than guessing with a static `- 2` offset, making it robust against lines that don't end in a newline.
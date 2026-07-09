## Problem: 
Write a program `detab` that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every *n* columns. Should *n* be a variable or a symbolic parameter?

## Re-phrased question:

Here's a clearer version of the problem:

---

**Problem: `detab`**

Write a C program that reads text from standard input and writes it to standard output, replacing each tab character with enough spaces to reach the next tab stop.

**Details:**

- Tab stops occur at fixed, regular column intervals — for example, every 8 columns (columns 1, 9, 17, 25, ...). You get to pick the interval, call it `n`.
- When the program encounters a tab character (`'\t'`) in the input, it should output enough space characters to advance the current column position to the next tab stop — *not* a fixed number of spaces every time. The number of spaces needed depends on where the cursor currently is on the line.
  - Example: if tab stops are every 8 columns and a tab occurs when the cursor is at column 3, output 5 spaces (to reach column 8/9, depending on how you index). If a tab occurs at column 9, output 8 spaces (to reach the next stop, column 17).
- All non-tab characters should be copied to the output unchanged.
- You'll need to track the current column position as you read through the input, resetting it appropriately when you hit a newline.

**Design question to think about:**
Should `n` (the tab stop interval) be a variable that could change at runtime, or a symbolic constant (e.g., defined via `#define`) fixed at compile time? Consider the tradeoffs — for instance, would a user ever want to change the tab width without recompiling? Does hardcoding it simplify the program? This is a design decision K&R wants you to consider, not something with one correct answer.
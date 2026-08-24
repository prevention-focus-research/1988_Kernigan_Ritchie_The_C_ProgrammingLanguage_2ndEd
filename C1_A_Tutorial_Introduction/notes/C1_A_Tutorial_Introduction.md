## 1.1: GETTING STARTED

Let's do the 'Hello, World!' program with the ANSI C programming language!

```c
#include <stdio.h>

main()
{
    printf("hello, world\n");
}
```

Running the program is system-dependent. On Unix, one creates a file ending wiht `".c"`, such as *hello.c*, then compile the program with the following command line statement:

```
$ cc hello.c
```

The compilation proceeds silently by default if the program did not err during compilation. The result of successful compilation is the executable named *a.out*. To run the executable, one executes the following statement on the command line:

```
$ a.out
```

When *a.out* is executed, the following is output to the console:

```
hello, world
```

### A CLOSER LOOK AT THE PROGRAM

A C program, regardless of size consists of *functions* and *variables*. A function contains *statements* that specify the computing operations to be done, and variables store values used during the computation. C functions are like the subroutines and function of 'Fortran' or the procedures and functions of 'Pascal'. Our example is a function named `main`. There is generally flexibility in functoin naming; however, `main` is special. One's program begins executing at the beginning of `main`. This means that every program must have a `main` somewhere.

`main` usually calls other functions -- either user-defined, or from provided libraries.

`#include <stdio.h>` located at line one of the *hello.c* program tells the compiler to include the information about the standard input/output library; this line appears at the beginning of many C source files. The standard library is described in *C7* and *Appendix B*. 

One approach to communicating data between functions is for the calling function to provide a list of values, called *arguments*, to the function it calls. The parentheses after the function name surrounds the argument list. In this example, `main` is defined to be a function that expects no arguments, which is indicated by the empty list `()`. 

The statements of a function are enclosed in braces `{}`. The function `main` contains only one statement:

```c
    printf("hello, world\n");
```

A function is called by naming it, followed by a parenthesized list of arguments, so this calls the function `printf` with the argument `"hello, world\n"`. `printf` is a library function that prints output, in this case the string of characters between the quotes. 

A sequence of characters in double quots, like `"hello, world"`, is called a *character string* or *string constant*. For the moment our only use of character strings will be as arguments for `printf` and other functions.

The sequence `\n` in the string is 'C' notation for the *newline character*, which when printed advances the output to the left margin on the next line. If one leavs out the `\n` (a worthwhile experiment), one will find that there is noline advance after the output is printed. One must use the `\n` to include a newline character in the `printf` argument; 

If one tries something like this:

```c
    printf("hello, world
    ");
```

the C compiler will produce an error message!

`printf` never supplies a newline automatically, so several calls may be used to build up an output line in stages. Our first program could just as well hve been written:

```c
#include <stdio.h>

main()
{
    printf("hello, ");
    printf("world");
    printf("\n");
}
```

to produce identical output.

Notice that `\n` represents only a single character. An *escape sequence* like `\n` provides a general and extensible mechanism for representing hard-to-type or invisible characters. Among the others C provides include `\t` for tab, `\b` for backspace, `\"` for the double quote, and `\\` for the backslash itself. There is a complete list in 'Section 2.3'.

**Exercise 1-1**: Run the "hello, world" program on one's system. Experiement with leaving out parts of the program to see which error messages are produced.

The following program:

```c
#include <stdio.h>

main()
{
    printf("hello, world\n")
}
```

produced the following error:
```
/src/ex1_1.c:7:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    7 | main()
      | ^~~~
/src/ex1_1.c: In function ‘main’:
/src/ex1_1.c:9:29: error: expected ‘;’ before ‘}’ token
    9 |     printf("hello, world\n")
      |                             ^
      |                             ;
   10 | }
      | ~    
```

**Exercise 1-2**: Experiment to find out what happens when `printf`'s argument string contains `\c`, where *c* is some character not listed above.

The following program:
```c
/* **Exercise 1-2**: Experiment to find out what happens when `printf`'s 
argument string contains `\c`, where *c* is some character not listed above. */

#include <stdio.h>

int main()
{
    printf("hello, wor\cld\n");
}
```

produced the following warning:
```
Starting build...
/usr/bin/gcc -fdiagnostics-color=always -g src/ex1_2.c -o src/../exec/ex1_2.out
src/ex1_2.c: In function ‘main’:
src/ex1_2.c:8:12: warning: unknown escape sequence: '\c'
    8 |     printf("hello, wor\cld\n");
      |            ^~~~~~~~~~~~~~~~~~

Build finished with warning(s).
```

and the following output:

```
hello, worcld
```

## 1.2: VARAIBLES AND ARITHMETIC

The next program uses the formula $\degree C = (5/9)(\degree F - 32)$ to pring the following table of Fahrenheit temperatures and their centigrade or Celsius equivalents. 

```
0    -17 
20   -6  
40   4   
60   15  
80   26  
100  37  
120  48  
140  60  
160  71  
180  82  
200  93  
220  104 
240  115 
260  126 
280  137 
300  148 
```

The program itself still consists of the definition of a single function named `main`. It is longer than the one that printed `"hello, world"`, but not complicated. It introduces several new ideas, including comments, declarations, variables, arithmetic expressions, loops, and formatted output.

**EXAMPLE PROGRAM**: *fahrenheit_celsius_table.c*
```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300 */

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */ 
    upper = 300;    /* upper limit of temperature table */ 
    step = 20;      /* step size */ 

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

The two lines 

```cpp
/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300 */
```

are a *comment*, which in this case briefly explins what the program does. Any characters between `/* */` are ignored by the compiler; they may be used freely to make a program easier to read. Comments may appear anywhere a blank or tab or newline can.

In C, all variables must be declared before they are used, usually at the beginning of the function before any executable statements. A *declaration* announces the properties of variables; it consists of a type name and a list of variables, such as:

```cpp
    int fahr, celsius;
    int lower, upper, step;
```

The type `int` means that the variables listed are integers, by contrast with `float`, which means floating point, i.e., numbers that may have a fractional part. The range of both `int` and `float` depends on the machine one is using; 16-bit `int`s, which lie between -32768 and +32767, are common, as are 32-bit `int`s. A `float` number is typically a 32-bit quantity, with at lest six significant digits and magnitude generally between about $10^{-38}$ and $10^{+38}$.

C provides several other basic data types besides `int` and `float`, including:

|type|description|
|:---|:---|
|`char`|character--a single byte|
|`short`|short integer|
|`long`|long integer|
|`double`|double-precision floating point|

The sizes of these objects are also machine-dependent. There are lso *arrays*, *structures*, and *unions* of these basic types, *pointers* to them, and *functions* that return them, all of which will be reviewed in due course!

Computation in the temperature conversion program begins with the *assignment statements*

```c
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
```

which set the variables to their initial values. Individual statements are terminated by semicolons.

Each lines of the table is computed the same way, so we use a loop that repeats once per output line; this is the purpose of the `while` loop:

```c
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
```

The `while` loop operates as follows: The condition in parentheses is tested. If it is true (`fahr` is less than or equal to `upper`), the body of the loop (the three statements enclsoed in braces) is executed. Then the condition is re-tested, and if true, the body is executed again. When the test becomes false (`fahr` exceeds `upper`), the loop ends, and execution continues at the statement that follows the loop. There are no further statements in this program, so it terminates. 

The body of a `while` can be one or more statements enclosed in braces, as in the temperature converter, or a single statement without braces, as in

```c
while (i < j)
    i = 2 * i;
```

In either case, indentation by one tab stop (4 spaces) makes it quickly see which statements are inside the loop. The indentation emphasizes the logical structure of the program. Although C compilers do not care about how a program looks, proper indentation and spacing are critical in making programs esy for people to read. Teach (BKDR) recommends writing only one statement per line, and using blanks around operators to clarify grouping. The position of braces is less important, although people hold passionate beliefs. BKDR have chosen one of several popular styles. The key is to pick one style, and then use it consistently!

Most of the work gets done in the loop's body. The Celsius temperature is computed and assigned to the varible `celcius` by the statement

```cpp
        celsius = 5 * (fahr-32) / 9;
```

The reason for multiplying by `5` and then dividing by `9` instead of just multipying by `5/9` is that in C, as in many other languages, integer division *trunctes*: any fractional part is discarded. Since `5` and `9` are integers, `5/9` would be truncated to zero and so all the 'Celsius' temperatures would be reported as zero. 

This example also shows a bit more of how `printf` works. `printf` is  general-purpose output formatting function, which BKDR will describe in detail in *C7*. It's first argument is  string of characters to be printed, with each `%` indicating where one of the other (second, third, ...) arguments is to be substituted, and in what ofrm it is to be printed. For instance, `%d` specifies an integer argument, so the statement:

```cpp
        printf("%d\t%d\n", fahr, celsius);
```

cuses the values of the two integers `fahr` and `celsius` to be printed, with a tab (`\t`) between them. 

Each `%` construction in the first argument of `printf` is paired with the corresponding second argument, third argument, etc.; they must match up properly by number and type, or one'll get incorrect output. 

`printf` is not part of the C language; there is not input or output defined in C itself. `printf` is just a useful function form the standard library of functions that are normally accessible to C programs. The behavior of `printf` is defined in the ANSI standard, however, so its properties should be the same with any compiler and library that conforms to the standard.

In order to concentrate on C itslef, BKDR will not discuss much about input and output until *C7*. In particular, BKDR will defer formatted input until then. If one has to input numbers, one should read the discussion of the function `scanf` in 'Section 7.4'. `scanf` is like `printf`, except that it reads input instead of writing output.

There are a couple of problems with the temperature conversion program. The simpler one is that the output isn't very pretty because the numbers are right-justified. That's easy to fix; if we ugment each `%d` in the `printf` statement with a width, the numbers printed will be right-justified in their fields. For instance, we might say:

```cpp
    printf("%3d %6d\n", fahr, celsius);
```

to print the first number of ech line in a field three digits wide, and the second in a field six digits wide, like this:

```
   0   -17
  20    -6
  40     4
  60    15
  80    26
 100    37
```

The more serious problem is that because we have used integer arithmetic, the 'Celsius' temperatures are not very accurate; for instance, $0 \degree F$ is actually about $-17.8 \degree C$, not $-17$. To get more accurate answers, we should use floating-point arithmetic instead of integer. This requires some changes in the program. Here is a second version:

**EXAMPLE PROGRAM**: *fahrenheit_celsius_table2.c*
```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */ 
    upper = 300;    /* upper limit of temperature table */ 
    step = 20;      /* step size */ 

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

This is much the same as before, except that `fahr` and `celsius` are declared to be `float`, and the formul for conversion is written in a more natural way. We were unable to use `5/9` in the previous version because integer division would truncate it to zero. A decimal point in a constant indicates that it is floating point, however, so `5.0/9.0` is not truncated because it is the ratio of two floating-point values. 

If an arithmetic operater has integer operands, an integer operation is performed. If an arithmetic operator has one floating-point operand and one integer operand, however, the integer will be converted to floating point before the operation is done. If we had written `fahr-32`, the `32` would be automatically converted to floating point. Nevertheless, writing floating-point constants with explicit decimal points evne when they have integral values emphasizes their floating-point nature for human readers.

The detiled rules for when integers are converted to floating point are in *C2*. For now, notice that the assignment `fahr = lower;` and the test `while (fahr <= upper)` also work in the natural way -- the `int` is converted to `float` before the operation is done.

The `printf` conversion specification `%3.0f` says that a floating-point number (here `fahr`) is to be printed at least three characters wide, with no deciml point an dno fraction digits. `%6.1f` describes another number (`celsius`) that is to be printed at least six characters wide, with `1` digit fter the decimal point. The output looks like this:

```
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

Width and precision my be omitted from a specification: `%6f` sys that the number is to be at least six characters wide; `%.2f` specifies two characters after the decimal point, but the width is not constrained; and `%f` merely says to porint the number as floating point.

|`printf` expression|description|
|:---|:---|
|`%d`|print as decimal integer|
|`%6d`|print as decimal integer, at least 6 characters wide|
|`%f`|print as floating point|
|`%6f`|ptins as floating point, at least 6 characters wide|
|`%.2f`|print as floating point, 2 characters after decimal point|
|`%6.2f`|print as floating point, at least 6 characters wide and 2 after decimal point|

Among others, `printf` also recognizes `%o` for octal, `%x` for hexadeciml, `%c` for character, `%s` for string, and `%%` for `%` itself.

**EXCERCISE 1-3**: Modify the temperature conversion program to print a heding above the table.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */ 
    upper = 300;    /* upper limit of temperature table */ 
    step = 20;      /* step size */ 

    fahr = lower;
    printf("Fahrenheit to Celsius Conversion Table\n\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

```
Fahrenheit to Celsius Conversion Table

  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

**EXCERCISE 1-4**: Write a program to print the corresponding Celsius to Fahrenheit table.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;      /* lower limit of temperature table */ 
    upper = 150;    /* upper limit of temperature table */ 
    step = 5;      /* step size */ 

    fahr = lower;
    printf("Celsius to Fahrenheit Conversion Table\n\n");
    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
```

the program above produces the following output:

```
Celsius to Fahrenheit Conversion Table

  0   32.0
  5   41.0
 10   50.0
 15   59.0
 20   68.0
 25   77.0
 30   86.0
 35   95.0
 40  104.0
 45  113.0
 50  122.0
 55  131.0
 60  140.0
 65  149.0
 70  158.0
 75  167.0
 80  176.0
 85  185.0
 90  194.0
 95  203.0
100  212.0
105  221.0
110  230.0
115  239.0
120  248.0
125  257.0
130  266.0
135  275.0
140  284.0
145  293.0
150  302.0
```

## 1.3: THE `for` STATEMENT

There are plenty of different ways to write a program for a particular task. Let's try a variation on the temperature converter:

**EXAMPLE PROGRAM**: *fahrenheit_celsius3.c*
```c
#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

output from the program above:

```
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

This program produces the same result, but it looks much different. One major change is the elimination of most of the variables; only `fahr` remains, and we have made it an `int`. The lower and upper limits and the step size appear only as constants in the `for` statement, itself a new construction, and the expression that computes the 'Celsius' temperature now appears as the third argument of `printf` instead of as a separate assignment statement.

This last change is an instance of a general rule -- in any context where it is permissible to use the value of a variable of some type, one can use a more compalicated expression of that type. Since the third argument of `printf` must be a floating-point value to match the `%6.1f`, any floating-point expression can occur there.

The `for` statement is a loop, a generaliztion of the `while`. If one compares it to the `while` loop introduced earlier, its operation should be clear. Within the parentheses, there are three parts, separated by semicolons (`;`). The first part, the initialization: `fahr = 0` is done once, before the loop is entered. The second part is the test or condition that controls the loop: `fahr <= 300`. This condition is evaluated; if it is true, the body of the loop (here a single `printf`) is executed. Then the increment step: `fahr = fahr + 20` is executed, and the condition re-evaluated. The loop terminates if the condition has become false. As with the `while` loop, the body of the loop can be a single statement, or a group of statements enclosed in braces. The initialization, condition, and increment can be any expression.

The coice between `while` and `for` is arbtrary, based on which seems clearer. The `for` is usually appropriate for loops in which the initialization and increment are single statements and logically related, since it is more compact than `while` and it keeps the loop control statements together in one place.

**EXCERCISE 1-5**: Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

```c
#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}```

output from the program above:

```
300  148.9
280  137.8
260  126.7
240  115.6
220  104.4
200   93.3
180   82.2
160   71.1
140   60.0
120   48.9
100   37.8
 80   26.7
 60   15.6
 40    4.4
 20   -6.7
  0  -17.8
```
```

## 1.4: SYMBOLIC CONSTANTS

A final observation before we leave temperature conversion forever. It's a bad practice to bury "magic numbers" like 300 and 20 in a program; they convey little information to someone who might have to read the program later, and they are hard to change in a systematic way. One way to deal with magic numbers is to give them meaningful names. A `#define` line define a *symbolic name* or *symbolic constant* to be a particular string of characters: `#define {name} {replacement text}`. Thereafter, any occurrence of name (not in quotes and not part of another name) will be replaced by the corresponding *replacement text*. The *name* has the same form as a variable name: a sequence of letters and digits that begins with a letter. The *replcement text* can be any sequence of characters; it is not limited ot numbers. 

**EXAMAPLE PROGRAM**: *fahrenheit_celsius4.c*
```c
#include <stdio.h>

#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit */
#define STEP 20     /* step size*/

/* print Fahrenheit-Celsius table */
int main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```

The program above produced the following output:
```
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

The quantities `LOWER`, `UPPER`, and `STEP` are symbolic constants, not variables, so they do not appear in declarations. Symbolic constant names are conventionally written in upper case so they can be readily distinguished form lower case variable names. Notice that there is no semicolon at the end of a `#define` line.

## 1.5: CHARACTER INPUT AND OUTPUT

We are not going to consider a family of related programs for processing character data. One will find that many programs are just expanded versions of the prototypes that we discuss here.

The model of input and output supported by the standard library is very simple. Text input or output, regardless of where it originates or where it gotes to, is dealth with as streams of characters. A *text stream* is a sequence of characters divided into lines; each line consists of zero or more characters follwoed by a newline character. It is the responsibility of the library to make input or output stream conform to this model; the C programmer using the library need not worry about how lines are represented outside the program. 

The standard library provides several functions for reading or writing one character at a time, of which `getchar` and `putchar` are the simplest. Each time it is called, `getchar` reads the *next input character* from a text stream and returns that as its value. Thhat is, after: `c = getchar()` the variable `c` contains the next character of input. The characters normally come from the keyboard; input from files is discussed in *C7*.  The function `putchar` prints a character each time it is called: `putchar(c)` prints the contens of the integer variable `c` as a character, usually on the screen. Calls to `putchar` and `printf` my be interleaved; the output will appear in the order in which the calls are made. 

### 1.5.1: FILE COPYING

Given `getchar` and `putchar`, one can write  surprising amount of uesful code without knowing anything more about input and output. The simplest example is a program that copies its input to its output one character at a time:

```
read a character
while (character is not end-of-file indicator)
    output the character just read
    read a character
```

Converting into c gives: 

**EXAMPLE PROGRAM**: *file_copying1.c*

```c
#include <stdio.h>

/* copy input to output; 1st version */

int main()
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

The relational operator `!=` means "not equal to."

What appears to be a character on the keyboard or screen is of course, like everything else, stored internally juts as a bit pattern. The type `char` is specifically meant for string such character data, but any integer type can be used. We used `int` for a sublte but important reason. 

The problem is distinguishing the end of the input from valid data. The solution is that `getchar` retusn a distinctive value when there is no more input, a vlaue that cannot be confused with any real character. This value is called `EOF`, for "end of file." We must declare `c` to be a type big enough to hold any value that `getchar` returns. We can't use `char` since `c` must be big enough to hold `EOF` in addition to any possible `char`. Therefore we use `int`. 

`EOF` is an integer defined in `<stdio.h>`, but the specific numberic value doesn't matter as along as it is not the same as any `char` value. By using the symbolic constant, we are assured that nothing in the program depends on the specific numeric value.

The program for copying would be written more concisely by experienced C programmers. In C, any assignment, such s `c = getchar()` is an expression and has a value, which is the value of the left hand side after the assignment. This means that an assignment can appear s part of a larger exprssion. If the assignment of a character to `c` is put inside the test part of a `while` loop, the copy program can be written this way:

**EXAMPLE PROGRAM**: *file_copying2.c*

```c
#include <stdio.h>

/* copy input to output; 2nd version */

int main()
{
    int c;
    
    while ((c = getchar()) != EOF) 
        putchar(c);
}
```

The `while` gets a character, assigns it to `c`, and then tests whether the characr was the end-of-life signal. If it was not, the boyd of the `while` is executed, printing the character. The `while` then repeats. When the end of the input is finally reached, the `while` terminates nd so does `main`. 

This version centralizes the input -- there is now only one reference to `getchar` -- and shrinks the program. The resulting program is more compact, and, once the idiom is mastered, easier to read. One'll see this style often. (It's possible ot get carried way and create impenetrable code, however,a tendency hat we will try to curb.)

The parentheses around the assignment within the condition are necessary. The *precedence* of `!=` is higher than that of `=`, which means that in the absence of the relational test `!=` woudl be done before the assignment `=`. So the statement `c = getchar() != EOF` is equivalent to `c = (getchar() != EOF)`. This hs the undesired effect of setting `c` to `0` or `1`, dependeing on whether or not the call of `getchar` encountered end of file. (More on this in *C2*). 

**Exercise 1-6**: Verify that the expression `getchar() != EOF` is 0 or 1.

```c
#include <stdio.h>

/* Verify that the expression `getchar() != EOF` is 0 or 1*/

int main(void) {
    int expression_value;

    printf("Enter a character (or signal EOF): ");
    
    // The expression 'getchar() != EOF' is evaluated, and its result (0 or 1) 
    // is assigned to 'expression_value'. The parentheses around 'getchar() != EOF'
    // explicitly show the order of operations, though due to precedence it's 
    // evaluated as is.
    expression_value = (getchar() != EOF);

    // Print the integer value of the expression.
    printf("The expression getchar() != EOF evaluated to: %d\n", expression_value);

    return 0;
}
```

**Exercise 1-7**: Write a program to print the value of `EOF`. 

```c
/* Write a program to print the value of EOF*/

#include <stdio.h>

int main() {
    printf("The value of EOF is: %d\n", EOF);
    return 0;
}
```

program output:

```
The value of EOF is: -1
```

### 1.5.2: CHARACTER COUTNING

The next program counts characters; it is similar to the copy program.

**EXAMPLE PROGRAM**: *character_counting.c*
```c
#include <stdio.h>

/* count characters in input: 1st version */

int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}
```

program output:
```
c
hello
8
```

The statement `++nc;` presents a new operator, `++`, which means *increment by one*. One coudl instead write `nc = nc + 1` but `++nc` i smore concise and often more efficient. There is a corresponding operator `--` to decrement by `1`. The operators `++` and `--` can be either prefix operators (`++nc`) or postfix (`nc++`); these two forms have different values in expressions, as will be shown in *C2*, but `++nc` and `nc++` both increment `nc`. For the moment we will stick to the prefix form. 

The character counting program accumulates its count in a `long` variable instead of an int. `long` integers are at least 32 bitsw. Although on some machines, `int` and `long` are the same size, on others an `int` is 16 bits, with a maximum value of 32767, and it would take relatively little input to overflow an `int` counter. The conversion specification `%ld` tells `printf` that the corresponding argument is a `long integer`. 

It may be possible to cope with even bigger numbers by using a `double` (double precision `float`). We will also use a `for` statement instead of a `while`, to illustrate way to write the loop:

**EXAMPLE PROGRAM**: *character_counting2.c*
```c
#include <stdio.h>

/* count characters in input: 2nd version */

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```

program output:
```
c
hello
8
```

`printf` uses `%f` for both `float` and `double`; `%0.f` suppresses printing of the decimal point and the fraction part, which is zero. 

The body of this `for` loop is empty because all of the work is done in the test and increment parts. But the grammatical rules of C require that a `for` statement have a body. The isolated semicolon, called a *null statement*, is there to satisfy that requirement. BTDR put it in a separate line ot make it visible.

Before moving on from the character counting program, observe that if the input contains no characters, the `while` or `for` test fails on the very first call to `getchar`, and the program produces zero, the right answer. This is important. One of te nice things about `while` and `for` is that they test at the top of the loop, before proceeding with the body. If there is nothing to do, nothing is done, even if that means never going through the loop body. Programs sould act inteligently when given zero-length input. The `while` and `for` statements help ensure that program do reasonable things with boundary conditions.

### 1.5.3: LINE COUNTING

The next program counts input lines. As BKDR mentioned above, the standard library ensures that an input text stream appears as a sequence of lines, each terminated by a newline. Hence, counting lines is just counting newlines:

**example program**: *line_counting.c*
```c
#include <stdio.h>

/* count lines in input */

int main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

program output:

```
c
d
e
hello
```

The body of the `while` now consists of an `if`, which in turn controls the increment `++nl`. The `if` statement tests the parenthesized condition, and if the condition true, executes the statement (or group of statements in braces) that follows. We have again intended to show what is controlled by what. 

The double equals sign `==` is the C notation for "is equal to" (like Pscl's single `=` or Fortran's `.EQ.`). This symbol is used to distinguish the equality test from the single `=` that C uses for assignment. A word of caution: newcomers to C occasionally write `=` when they mean `==`. As will be seen in *C2*, the result is usually a legal expression, so one will ge no warning. 

A character written between single quotes represents an integer value equal to the numerical value of the character in the machine's character set. This is called a *charactr constant*, although it is just another way to write  small integer. So, for example, `'A'` is a character constant; in the ASCII chracter set its' value is 65, the internal representiaotn of the character `**A**`. Of course, `'A'` sets its value to be preferred over `65`: its meaning is obvious, and it is independent of a particular character set. 

The escape sequence used in string constants are also legal in character constants, so `'\n'` stands for the value of the newline character, which is `10` in ASCII. One should note carefully that `'\n'` is a single character, and in expressions is just an integer; on the other hand, `"\n"` is  string constant that happens ot contain only one character. the topic of strings versus characters is discussed further in *C2*. 

**Exercise 1-8**: Write a program to count blanks, tabs, and newlines.

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
}```

program output:
```
hello   world?
hello           world?
yo, what's good with you??
blanks: 7; tabs: 2; newlines: 3
```

**Exercise 1-9**: Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

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

program output:

```
hello there!
hello there!
hello   there!
hello there!
hello!
hello!
```

**Exercise 1-10**: Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`. This makes tabs and backspaces visible in an unambiguous way. 

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

program output:

```
hello   world
hello\tworld
hello\\world
hello\\\\world
hellworld
hellworld
hello   world
hello   world
```

### 1.5.4: WORD COUNTING

The fourth in the series of useful programs counts lines, words, and characters, with the loose definition that a word is any sequence of characters that does not contain a blank, tab, or newline. This is a bare-bones version of the UNIX program `wc`: 

**EXAMPLE PROGRAM**: *word_counting.c*
```c
#include <stdio.h>

#define IN  1   /* inside a word*/ 
#define OUT 0   /* outside a word*/

/* count lines, words, and characters in input */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state = OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```

program output:

```
yo, what's good with you?
it's all g!
2 0 38
```

Every time the program encounters the first character of a word, it counts one word. The variable `state` records whether the program is currently in a word or not; initially it is "not in a word," which is assigned the value of `OUT`. We prefer the symbolic constants `IN` and `OUT` to the literal values `1` and `0` because they make the program more readable. In a program as tiny as this, it makes little difference, but in larger programs, the increase in clarity is well worth the modest extra effort to write it this way from the beginning. One'll also find that it's easier to make extensive changes in programs where magic numbers appear only as symbolic constants. 

The line `nl = nw = nc = 0;` sets all three variables to zero. This is not a special case, but a consequence of the fact that an assignment is an expression with a value and assignments associate from right to left. It's as if we had written: `nl = (nw = (nc = 0));`

The operator `||` means `OR`, so the line `if (c == ' ' || c == '\n' || c == '\t')` says "if `c` is a blank *or* `c` is a newline *or* `c` is a tab". (Recall that the escape sequence `\t` is a visible representation of the tab character.) There is corresponding operator `&&` for `AND`; its precedence is just higher than `||`. Expressions connected by `&&` or `||` are evaluated left to right, and it is auaratneed that evaluation will stop as soon as the truth or falsehood is known. If `c` is a blank, there is no need to test whether it is a newline or tab, so these tests are not made. This isn't particularly important here, but is significant in more complicated situations, as we will soon see.

The example also shows an `else`, which specifies an alternative action if the condition part of an `if` statement is false. The general form is:

```c
    if (expression)
        statement1;
    else
        statement2;
```

One and only of the two statements associated with an `if`-`else` is performed. If the *expression*is true, *statement1* is executed; if not, *statement2* is executed. Each *statement* can be a single statement or several in braces. In the word count program, the other after the `else` is an `if` that controls two statements in braces. 

**Exercise 1-11**: How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

```c
/* How would you test the word count program? What 
kinds of input are most likely to uncover bugs if 
there are any?*/

/* I need to test what happens when input words with newline characters `\n`,
blanks, `' '`, and tabs `\t`. */

#include <stdio.h>

#define IN  1   /* inside a word*/ 
#define OUT 0   /* outside a word*/

/* count lines, words, and characters in input */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state = OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```

**Exercise 1-12**: Write a program that prints its input one word per line.

```c
/* Write a program that prints its input one word per line*/

#include <stdio.h>

int main()
{
    int c;
 
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');            
        }            
        else {
            putchar(c);
        }
    } 
    return 0;
}
```

output:

```
hello world
hello
world
what's your name?
what's
your
name?
my name is John B!
my
name
is
John
B!
```
## 1.6: ARRAYS

Let us write a program to count the number of occurrences of each digit, of white space characters (blank, tab, newline), and all other characters. This is artificial, but it permits us to illustrate several aspects of C in one program.

There are twelve categories of input, so it is convenient to use an array to hold the number of occurrences of each didit, rather than ten individual variables. Here is one version of the program:

**EXAMPLE PROGRAM**: *couting_digits_ws_others.c*
```c
#include <stdio.h>

/* count digits, white space, others*/

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
        nwhite, nother);
}
```

output of this program:

```
digits = 9 3 0 0 0 0 0 0 0 1, white space = 123, other = 345
```

The declaration `int ndigit[10];` declares `ndigit` to be an array of 10 integers. Arrray subscripts alwasy start at zero in C, so the elmeents are `ndigit[0]`, `ndigit[1]`, ..., `ndigit[9]`. This is reflected in the `for` loops that initialize and print the array. 

A subscript can be any integer expression, which includes integer variables like `i`, and integer constants.

This particular program relies on the properties of the character representation of the digits. For example, the test `if (c >= '0' && c <= '9')` determines whether the character in `c` is a digit. If it is, the numeric value of the digit is `c - '0'`. This works only if `'0'`, `'1'`, ..., `'9'` have consecutive increasing values. Fortunately, this is true for all character sets.

By definition, `char`s are just small integers, so `char` variables and constants are identical to `ints` in arithmetic expressions. This is natural and convenient; for example, `c-'0'` is an integer expression with a value between `0` and `9` corresponding to the character `'0'` to `'9'` stored in `c`, and is thus a valid subscript for teh array `ndigit`. 

The decision as to whether a character is a digit, white space, or something else is made with the sequence: 

```c
       if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
```

The pattern 

```c
       if (condition1)
            statement1;
        else if (condition2)
            statement2

        ...
            ...

        else
            statementn;
```

occurs frequently in programs as a way to express a multi-way decision.  The *conditions* are evaluated in order from top until some *condition* is satisfied; at that point the corresponding *statement* part is executed, and the entire construction is finished. (Any *statement* can be several statements enclosed in braces.) If none of the conditions is satisfied, the *statement* after the final `else` is executed if it is present. If the final `else` and *statement* are omitted, as in the word count program, no action takes place. There can be any number of 

```c
else if (*condition*)
    *statement*
```

groups between the initial `if` and the final `else`. 

As a matter of style, it is advisable to format this construction as we have shown; if each `if` were indented pst the previous `else`, a long sequence of decisions would march off the right side of the page. 

The `switch` statement, to be discussed in *C3*, provides another way to write a multi-way branch that is particularly suitable when the condition is whether soem integer or character expression matches one of a set of constants. For contrast, BKDR will present a `switch` version of this program in 'Section 3.4'.

**Exercise 1-13**: Write a program to print a histogram of the lengths of words in its input. It is easy to draw a histogram with the bars horizontal;  vertical orientation is more challenging.

**horizontal version**:

```c
/* Write a program to print a histogram of the lengths of words in 
its input. It is easy to draw a histogram with the bars horizontal;  
vertical orientation is more challenging*/

#include <stdio.h>

#define IN  1   /* inside a word*/ 
#define OUT 0   /* outside a word*/

int main()
{
    int c, i, wlength, state;

    state = OUT;
    wlength = 0;
    while ((c = getchar()) != EOF) {
        ++wlength;
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("%d: ", (wlength-1));
            for (i = 0; i < (wlength-1); ++i) {
                printf("*");
            }
            printf("\n");
            state = OUT;
            wlength = 0;
        }            
        else if (state = OUT) {
            putchar(c);
            state = IN;
        }
    }
    return 0;    
}
```

program output:
```
hello world
5: *****
5: *****
what is your name?
4: ****
2: **
4: ****
5: *****
that is pretty awesome!
4: ****
2: **
6: ******
8: ********
^C
```

**vertical version**: 

```c
/* Write a program to print a histogram of the lengths of words in 
its input. It is easy to draw a histogram with the bars horizontal;  
vertical orientation is more challenging*/

/*VERTICAL VERSION*/

/* Program 2: Vertical histogram of word lengths */
/* ANSI C - K&R style */

#include <stdio.h>

#define MAX_WORD_LEN 20   /* words longer than this are capped */

int main(void)
{
    int c;
    int len = 0;
    int hist[MAX_WORD_LEN + 1] = {0};
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (len > 0) {
                if (len > MAX_WORD_LEN)
                    len = MAX_WORD_LEN;
                hist[len]++;
                len = 0;
            }
        } else {
            len++;
        }
    }
    
    /* last word */
    if (len > 0) {
        if (len > MAX_WORD_LEN)
            len = MAX_WORD_LEN;
        hist[len]++;
    }
    
    /* Find maximum frequency for vertical scale */
    int max_freq = 0;
    for (int i = 1; i <= MAX_WORD_LEN; i++) {
        if (hist[i] > max_freq)
            max_freq = hist[i];
    }
    
    /* Print vertical histogram */
    printf("Vertical word length histogram:\n\n");
    
    /* Print bars from top to bottom */
    for (int row = max_freq; row > 0; row--) {
        for (int i = 1; i <= MAX_WORD_LEN; i++) {
            if (hist[i] >= row)
                putchar('*');
            else
                putchar(' ');
            putchar(' ');   /* spacing between columns */
        }
        putchar('\n');
    }
    
    /* Print x-axis (word lengths) */
    for (int i = 1; i <= MAX_WORD_LEN; i++)
        printf("%-2d", i);   /* two characters per column */
    putchar('\n');
    
    return 0;
}
```

program output
```
hello world!
what is good with you?
this is john b!
life can get really complicated!
Vertical word length histogram:

      *                                 
      *                                 
      *                                 
      *                                 
  *   *                                 
  * * *   *                             
  * * * * *           *                 
1 2 3 4 5 6 7 8 9 1011121314151617181920
```

**Exercise 1-14**: Write a program to print a histogram of different characters in its input.

```c
/* Write a program to print a histogram of different characters in 
its input. */

#include <stdio.h>

/* Maximum number of different characters in standard ASCII */
#define MAX_CHARS 256

int main() {
    int c, i, j;
    int counts[MAX_CHARS];

    /* Initialize all character counts to zero */
    for (i = 0; i < MAX_CHARS; i++) {
        counts[i] = 0;
    }

    /* Read characters until end of input */
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < MAX_CHARS) {
            counts[c]++;
        }
    }

    printf("\nCharacter Frequency Histogram:\n");

    /* Loop through the array and print a bar for characters that appeared */
    for (i = 0; i < MAX_CHARS; i++) {
        if (counts[i] > 0) {
            /* Format the label for readability */
            if (i == ' ') {
                printf("' ' : ");
            } else if (i == '\n') {
                printf("'\\n': ");
            } else if (i == '\t') {
                printf("'\\t': ");
            } else if (i >= 32 && i <= 126) {
                printf("'%c' : ", i);
            } else {
                printf("0x%02X: ", i); /* Hex for non-printables */
            }

            /* Print a bar of '#' characters representing the frequency */
            for (j = 0; j < counts[i]; j++) {
                putchar('#');
            }
            printf(" (%d)\n", counts[i]);
        }
    }

    return 0;
}
```

program output:
```
hello world

Character Frequency Histogram:
'\n': # (1)
' ' : # (1)
'd' : # (1)
'e' : # (1)
'h' : # (1)
'l' : ### (3)
'o' : ## (2)
'r' : # (1)
'w' : # (1)
```

## 1.7: FUNCTIONS

In C, a function is equivalent to a subroutine or function in Fortran, or a procedure or function in Pascal. A function provides a convenient way to encapsulate some computation, which can then be used without worrying about its implementation. With properly designed functions, it is possibe to ignore *how* a job is done; knowing *what* is done is sufficient. C makes the use of functions easy, convenient and efficient; one will often see a short function defined and called only once, just because it clarifies some piece of code.

So far we have used only funciton like `printf`, `getchar`, and `putchar` that have been provided for us; now it's time to write a few of our own. Since C has no exponentiation operator like the `**` of 'Fortran', let us illustrate the mechanics of function definition by writing a function `power(m,n)` to raise an integer `m` to a positive integer power `n`. That is, the value of `power(2,5)` is `32`. This function is not a practical exponentiation routine, since it handles only positive powers of small integers, but it's godo enough for illustration. (The standard library contains a function `pow(x,y)` that computes $x^y$).

Here is the function `power` and a main program to exercise it, so one can see the whole structure all at once:

**EXAMPLE PROGRAM**: *power_function.c*
```c
#include <stdio.h>

int power(int m, int n);

/* test power function */
int main()
{
   int i;

   for (i = 0; i < 10; ++i)
       printf("%d %d %d\n", i, power(2,i), power(-3,i));
}

/* power: raises base to n-th power; n >=0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```

program output:
```
0 1 1
1 2 -3
2 4 9
3 8 -27
4 16 81
5 32 -243
6 64 729
7 128 -2187
8 256 6561
9 512 -19683
```

A function has this form:

*return-type* *function-name*(*parameter declarations, if any*)
{
    *declarations*
    *statements*
}

Function definitions can appear in any order, and in one source file or several, although no functoin can be split between files. If the source program appears in several files, one may have to say more to compile and load it than if it all appears in one, but that is an OS matter, not a language attribute. For the momeent, we will assume that both functions are in the same file, so whateer one has learned about running C programs will still work.

The function power is called `twice` by `main` in the line: `printf("%d %d %d\n", i, power(2,i), power(-3,i));`. Each call passes two arguments to `power`, which each time returns an integer to be formatted and printed. In an expression, `power(2,i)` is an integer just as `2` and `i` are. (Not all functions produce an integer value; we will take this up in *C4*.)

The first line of `power` itself, `int power(int base, int n)`, declares the parameter types and names, and the type of the result that the function returns. The names used by `power` for its parameters are local to `power`, and are not visible to any other function: other routines can use the same names without conflict. This is also true of the varibles `i` and `p`: the `i` in `power` is unrleated to the `i` in `main`.

BKDR will generally use *parameter* for a variable named in the parenthesized lsit in a funciton definition, and *argument* for the value used in a call of the function. the terms *formal argument* and *actual argument* are sometimes used for the same distinction. 

The value that `power` computes is returned to `main` by the `return` statement. Any expression may follow `return`: `return *expression*;`

A function need not return a value; a `return` statement with no expressoin causes control, but no useful value, to be returned to the caller, as does "falling off the end" of a funciton by reaching the terminating right brace. And the calling funciton can ignore a value returned by a function. 

One may have noticedf that there is a `return` statement at the end of `main`. Since `main` is a funciton like any other, it my return a value to its caller, which is in effect the environment in which the program was executed. Typically, a return value of zero implies normal termination; non-zero values signal unusual or erroneous termination conditions. In the interests of simplicity, BIDR  omitted `return` statements from `main` fuctions up to this point, but will include them hereafter, as a reminder that programs shoudl return status to their environment.

The declaration `int power(int m, int n);` just before `main` says that `power` is a functon that expects two `int` arguments and returns an `int`. This declaration, which is called a *function prototype*, has to agree with the definition and uses of `power`. It is an error if the definition of a function or any uses of it do not agree with its protoype. 

Parameter names need not agree. Indeed, parameter names are optional in a function prototype, so for the prototype, one could have written `int power(int, int);`. Well-chosen names are good documentaiton, however, so BKDR will often use them. 

A note of history: The biggest change between ANSI C and earlier versions is how functions are declared and defined. In the original definition of C, the power function would have been writtne as follows:

**EXAMPLE PROGRAM**: *power_function2.c* (different than program below)
```c
#include <stdio.h>

/* power: raise base to n-th power; n >= 0 */
/*        (old-style version) */

power(base, n)
int base, n;
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```

The parameters are named between the parentheses, and their types are declared before the opening left brace; undelcared parameters are taken as `int`. (the body of the function is the same as before.)

The declaration of `power` at the beginning of the program would have looked like this: `int power();`. No parameter list was permitted, so the compiler would not readily check that `power` was being called correctly. Indeed, since by default `power` would have been assumed to return ain `int`, the entire declarations might well have been omitted.

The new syntax of function prototypes makes it much easier for a compiler to detect errors in the number of argumnents or their types. The old style of declaration and definition still works in ANSI C, at least for a transition period, but BKDR strongly recommends that one use the new form when one has a compiler that support it. 

**EXERCISE 1-15**: Rewrite the temperature conversion program of 'Section 1.2' to use a function for conversion.
```c
#include <stdio.h>

float getcelsius(float fahr);

/* Rewrite the temperature conversion program of 'Section 1.2' 
to use a function for conversion.*/

float getcelsius(float fahr)
{
    float celsius;
    celsius = 5 * (fahr-32) / 9;
    return celsius;
}
   

/* print Fahrenheit-Celsius table
     for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */ 
    upper = 300;    /* upper limit of temperature table */ 
    step = 20;      /* step size */ 

    fahr = lower;
    while (fahr <= upper) {
        celsius = getcelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

program output:
```
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9
```

## 1.8: ARGUMENTS -- CALL BY VALUE

One spect of C functions my be unfamiliar to programmers who are used to some other languages, particulalry 'Fortran'. In C, all function arguments are passed "by value." This means that the called function is given the values of its arguments in temporary variables rather than the originals. This leads to some different properties than are seen with "call by reference" languages like 'Fortran' or with `var` parameters in 'Pascal', in which the called routine hs access to the originl argument, not a local copy. 

The main distinction is that in C the called function cannot directly alter a variable in the calling function; it can only alter its private, temporary copy.

Call by value is an asset, however, not a liability. It usually leads tomore compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine. For example, here is a version of `power` that make use of this property:

**EXAMPLE PROGRAM**: *power_function3.c*

```c
/* power: raise base to n-th power; n>=0; version 2 */ 
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```

The parameter `n` is used as a tempoary variable, and is counted down (a for loop that runs backwards) until it becomes zero; there is no longer a need for the variable `i`; Whatever is done to `n` inside has no effect on the argument that `power` was originally called with.

When necessary, it is possible to arrange for a function to modify a variable in a calling routine. The caller must provide the *address* of the variable to be set (technically a *pointer* to the variable), and the called function must declare the parameter to be a pointer and access the variable indirectly through it. We will cover pointers in *C5*. 

The sotry is different for arrays. When the name of an array is used as an argument, the value passed to the function is the location or address of the beginning of the array -- there is no copying of array elements. By subscripting this value, the function can access and alter any element of the array. This is the topic of the next section. 

## 1.9: CHARACTER ARRAYS

The most common type of array in C is the array of characters. To illustrate the use of character arrays and functions to manipulate them, let's write a program that reads a set of text lines and prints the longest. The outline is simple enough:

    `while` (*there's another line*)
        `if` (*it's longer than the previous longest*)
            *save it*
            *save its length*
    *print longest line*

This outline makes it clear that the program divides naturally into pieces. One piece gets a new line, anohter tests it, another saves it, and the rest controls the process.

Since things divide so nicely, it would be well to write them that way too. Accordingly, let us first write a separate function `getline` to fetch the next line of input. We will try to make the function useful in other contexts. At the minimum, `getline` has to return a signal about possible end of file; a more useful design would be to return the length of the line, or zero if end of file is encountered. Zero is an acceptable end-of-file return because it is never a valid line length. Every text line has at least one character; even a line containing only a newline has length 1.

When we find a line that is longer than the previous longest line, it must be saved somewhere. This suggests a second function, `copy`, to copy the new line to a safe place.

Finally, we need a main program to control `getline` and `copy`. Here is the result:

**EXAMPLE PROGRAM**: *get_longest_line.c*
```c
#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() 
{
    int len;                /* current line length */
    int max;                /* maximum length seetn so far*/
    char line[MAXLINE];         /* current input line*/
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
};

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
```

program output:

```
a
abcd
abcdefg
hijklmnop
hijklmnop
```

The functions `getline` and `copy` are declared at the beginning of the program, which we assume is contained in one file.

`main` and `getline` communicate through a pair of arguments and a returned value. In `getline`, the arguments are declared by the line `int getline(char s[], int lim)` which specifies that the first argument, `s`, is an array, and the second, `lim`, is an integer. The purpose of supplying the size of an array in a declaration is to set aside storage. The length of the array `s` is not necessary in `getline` since its size is set in `main`. `getline` uses `return` to send a value back to the caller, just as the function `power` did. This line also declares that `getline` returns an `int`; since `int` is the default return type, it could be omitted. 

Some functions return a useful value; others, like `copy`, are used only for their effect and return no value. The return type of `copy` is `void`, which sates explicitly and no value is returned. 

`getline` puts the character `'\0'` (the *null character*, whose value is zero) at the end of the array it is creating, to mark the ned of the string of characters. This convention is also used by the C language: when a string constant like `"hello\n"` appears in a C program, it is stored as an array of characters containing the characters of the string and terminated with a `'\0'` to mark the end:

||||||||
|:---|:---|:---|:---|:---|:---|:---|
|`h`| `e`|`l`|`l`|`o`|`\n`|`\0`|

The `%s` format specification in `printf` expects the corresponding argument to a string represented in this form. `copy` also relies on the fact that its input argument is terminated by `'\0'`, and it copies this character into the output argument. (All of this implies that `'\0'` is not a part of normal text.)

It is worth mentioning in passing that even a program as small as this one presents some sticky design problems. For example, what should min do if it encounters a line which is bigger than its limit? `getline` works safely, in that it stops collecting when the array is full, even if no newline has been seen. By testing the length and the last character returned, `main` cna determine whether the line was too long, and then cope as it wishes. In the interests of brevity, BKDR have ignored the issue.

There is no way fo ra user of `getline` to know in advance how long an input line might be, so `getline` checks for overflow. On the other hand, the user of `copy` already knows (or can find out) how big the strings are, so we have chosen not to add error checking to it. 

**Exercise 1-16**: Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.

```c
#include <stdio.h>

/* Exercise 1-16: Revise the main routine of the longest-line program 
so it will correctly print the length of arbitrarily long input lines, 
and as much as possible of the text. */

#define MAXLINE 1000        /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() 
{
    int len;                /* current line length */
    int max;                /* maximum length seetn so far*/
    char line[MAXLINE];         /* current input line*/
    char longest[MAXLINE];      /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("The longest line is %d characters long.", max);
        printf("\n");
        printf("The line is: %s", longest);
        
    return 0;
};

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
```

output:

```
hello world
what is your name?
The longest line is 19 characters long.
The line is: what is your name?
```

**Exercise 1-17**: Write a program to print all input lines that are longer than 80 characters.

```c


/* Exercise 1-16: Write a program to print all input lines that are 
longer than 80 characters */

#include <stdio.h>

#define MAXLINE 1000    /* Maximum input line length */
#define LIMIT 80        /* Threshold for printing */

int getline(char line[], int maxline);

int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > LIMIT) {
            printf("%s", line);
        }
    }

    return 0;
}

/* Function to read a line into s, return length */
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
```

program output:

```
hello world
what's your name?
....................................................................................
....................................................................................
hello...............................................................................
hello...............................................................................
```

**Exercise 1-18**: Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

```cpp


/* Exercise 1-18: Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. */

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

### program output
```
hello world
hello world
hello           world
hello           world
  
hello world  
hello world
```

**Exercise 1-19**: Write a function `reverse(s)` that reverses the character string `s`. Use it to write a program that reverses its input a line at a time.

#### my solution
```c


/* Exercise 1-19: Write a function `reverse(s)` that reverses the character 
string `s`. Use it to write a program that reverses its input a line at a 
time. */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
void reverse_copy(char to[], char from[]);

int main(void) {
    char line[MAXLINE];
    char reversed[MAXLINE];
    int len;

    /* Read each line from standard input */
    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse_copy(line, reversed);
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

void reverse_copy(char original[], char reversed[])
{
    int i, len, tlen;

    len = get_line(original, MAXLINE);
    tlen = len-2;


    for (i = 0; i <= tlen; ++i) {
        reversed[i] = original[tlen-i];
    }
    reversed[tlen+1] = '\n';
    reversed[len] = '\0';    
}
```

#### program output:
```
hello
hello
The reversed line is: olleh
world
world
The reversed line is: dlrow
```


#### alternative solution
```c


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
```

#### program output

```
hello
olleh
world
dlrow
damn
nmad
```

#### corrected program:
```c


/* Exercise 1-19: Write a function `reverse(s)` that reverses the character 
string `s`. Use it to write a program that reverses its input a line at a 
time. */

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

#### program output:
```
hello
The reversed line is: olleh
world
The reversed line is: dlrow
damn
The reversed line is: nmad
what's good?
The reversed line is: ?doog s'tahw
racecar
The reversed line is: racecar
```

## 1.10: EXTERNAL VARIABLES AND SCOPE

The variables in `main`, such as `line`, `longest`, etc., are private or local to `main`. Because they are declared within `main`, no other function can have dircect access to them. The same is true of the variables in other functions; for example, the variabel `i` in `getline` us unrelated to the `i` in `copy`. Each local variable in a function comes into existence only when the function is called, and disappears when the function is exited. This is why such variables are usually known as *automatic* variables, following terminology in other languages. We will use the term automatic henceforth to refer to these local variables. (*C4* discusses the `static` storage class, in which local variables do retain their values between calls.)

Because automatic variables come and go with function invocation, they do not retain their values from one call to the next, and must be explicitly set upon each entry. If they are not set, they will contain garbage.

As an alternative to automatic variables, it is possible to define variables that are *external* to all functions, that is, variables that can be accessed by name by any function. (This mechanism is rather like Fortran COMMON or Pascal variables declared in the outermost block.) Because external variables are globally accessible, they can be used instead of argument lists to communicate data between functions. Furthermore, because external variables remain in existence permanently, rather than appearing and disappearing as functions are called and exited, they retain their values even after the functions that set them have returned. 

An external variable must be *defined*, exactly once, outside of any function; this sets aside storage for it. The variable must also be *declared* in each function that wants to access it; this states the type of the variable. The declaration may be an explicit `extern` statement or may be impliccit from context. To make the discussion concrete, BKDR will rewrite the longest-line program with the `line`, `longest`, and `max` as external variables. This requires changing the calls, declarations, and bodies of all three functions.

**EXAMPLE PROGRAM**: *get_longest_line_ext_vars.c*
```c
#include <stdio.h>

#define MAXLINE 1000        /* maximum input line size */

int max;                    /* maximum length seen so far */
char line[MAXLINE];         /* current input line */
char longest[MAXLINE];      /* longest line saved here */

int getline(void);
void copy(void);

/* print longest input line; specialized version */
main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline()) > 0)
        if (len > max) {
            max = len;
            copy();
        }
    if (max > 0)    /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline: specialized version */
int getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1
        && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\n';
    return i;
}

/* copy: specialized version */
void copy(void){
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
```

### program output:
```
hello world
what is your name?
what is your name?
```

The external variables in `main`, `getline`, and `copy` are defined by the first lines of the example, which specifies each external variable's type and cause storage to be allocated for them. Syntactically, external definitions are just like definitions of local variables, but since they occur outside of functions, the variables are external. Before a function can use an external variable, the name of the variable must be made known to the function. One way to do this is to write an `extern` declaration in the function; the declaration is the same as before except for the added keyword `extern`. 

In certain circumstances, the `extern` declaration can be omitted. If the definition of an external variable occurs in the source file before its use in pa particular function, then there is no need for an `extern` declaration in the function. The `extern` declarations in `main`, `getline` and `copy` are thus redundant. In fact, common practice is to place definitions of all external variables at the beginning of the source file, and then omit all `extern` declarations.

If the program is several source files, and a variable is defined in *file1* and used in *file2* and *file3*, then `extern` declarations are needed in *file2* and *file3* to connect the occurrences of the variable. The usual practice is to collect `extern` declarations of variables and functions in a separate file, historically called a *header*, that is included by `#include` at the front of each source file. The suffix `.h` is conventional for header names. The functions of the standard library, for example, are declared in headers like `<stdio.h>`. This topic is discussed at length in *C4*, an dthe library itself in *C7* and *Appendix B*. 

Since the specialized versions of `getline` and `copy` have no arguments, logic would suggest that their prototypes at the beginning of the file should be `getline()` and `copy()`. But for compatibility with older C programs the standard takes an empty list as an old-style declaration, and turns off all arugment list checking; the word `void` must be used for an explicitly empty list. BKDR will discus this further in *C4*.

One should note that BKDR using the words *definition* and *declaration* carefully when referring to external variables in this section. "Definition" refers to the place where the variable is created or assigned storage; "declaration" refers to places where the nature of the variable is stated but no sotrage is allocated. 

By the way, there is a tendency to make everything in sight an `extern` variable because it appears to simplify communications -- argument lists are short and variables are always there when one wants them. But external varibles are always there even when one doesn't want them. Relying too heavily on external variables is fraught with peril since it leads to programs whose data connections are not at all obvious -- variables can be chagned in unexpected and even inadvertent ways, and the program is hard to modify. the second version of the longest-line program is inferior to the first, partly for these reasons, and partly because it destroys the generality of two useful functions by wriring into them, the names of the variables they manipulate. 

At this point BKDR have covered what might be called the conventional core of C. With this handful of building blocks, it's possible to write useful programs of considerable size, and it would probably be a good idea if one paused long enough to do so. These exercises suggest programs of somewhat greater complexity than the ones earlier in this chapter. 

**Exercise 1-20**: Write a program `detab` that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every *n* columns. Should *n* be a variable or a symbolic parameter?

<!-- HERE -- ex 1-20, p. 34
+++++++
+++++++
+++++++
+++++++
+++++++
+++++
++! -->
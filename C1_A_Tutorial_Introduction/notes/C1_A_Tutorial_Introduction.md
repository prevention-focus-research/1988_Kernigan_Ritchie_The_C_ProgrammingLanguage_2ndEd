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

A C program, regardless of size consists of *functions* and *varibles*. A function contains *statements* that specify the computing operations to be done, and variables store values used during the computation. C functions are like the subroutines and function of 'Fortran' or the procedures and functions of 'Pascal'. Our example is a function named `main`. There is generally flexibility in functoin naming; however, `main` is special. One's program begins executing at the beginning of `main`. This means that every program must have a `main` somewhere.

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

<!-- HERE -- p. 18! -->
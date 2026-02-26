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

Most of the work gets done in the loop's body. ...

<!-- HERE -- p. 10! -->
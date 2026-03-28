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
        if (c == '\b')
            ++nb;
    }
    printf("blanks: %d; tabs: %d; newlines: %d\n", nb, nt, nl);
}
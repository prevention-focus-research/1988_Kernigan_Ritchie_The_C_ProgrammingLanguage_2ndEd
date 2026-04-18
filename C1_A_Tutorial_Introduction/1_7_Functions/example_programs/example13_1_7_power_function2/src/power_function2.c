#include <stdio.h>

/* power: raise base to n-th power; n >= 0 */
/*        (old-style version) */

int power(base, n)
int base, n;
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

int main() {
    return 0;
};
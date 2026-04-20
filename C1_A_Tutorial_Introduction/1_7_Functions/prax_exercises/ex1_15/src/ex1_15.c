#include <stdio.h>

/* Rewrite the temperature conversion program of 'Section 1.2' 
to use a function for conversion.*/

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

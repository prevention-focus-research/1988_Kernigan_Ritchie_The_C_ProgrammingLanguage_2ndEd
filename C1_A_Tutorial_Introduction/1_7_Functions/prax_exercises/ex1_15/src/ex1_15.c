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

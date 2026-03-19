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

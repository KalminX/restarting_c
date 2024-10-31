#include <stdio.h>

/* This function adds two numbers */
int add(int a, int b) {
    return a + b; /* Return the sum of a and b */
}

/* This function multiplies two numbers */
int multiply(int a, int b) {
    return a * b; // Multiply a and b
}

int main() {
    int x = 5;
    int y = 10;

    /* Call the add function */
    int sum = add(x, y); /* sum should be 15 */
    
    // Print the sum result
    printf("Sum: %d\n", sum);
    
    /* Call the multiply function */
    int product = multiply(x, y); // product should be 50
    
    // Print the product result
    printf("Product: %d\n", product);
    
    return 0; // Exit the program
}


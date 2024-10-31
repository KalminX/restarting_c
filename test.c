#include <stdio.h>

// Function to print current and previous elements of an array
void print_previous_elements(int *p) {
    // Print the current element
    printf("Current element: %d\n", *p);

    // Check if we can safely access the previous element
    printf("Previous element: %d\n", *(p - 1));  // p[-1]

    // Check if we can safely access two elements back
    if (p > (p - 2)) {  // Ensure p is not at the beginning of the array
        printf("Two elements back: %d\n", *(p - 2));  // p[-2]
    } else {
        printf("Two elements back: Access out of bounds\n");
    }
}

int main() {
    int arr[] = {10, 20, 30, 40};  // An array of integers

    // Pass the address of the second element
    printf("Testing with the second element:\n");
    print_previous_elements(&arr[1]);  // Should print 20 (current), 10 (previous), and a warning for two back

    printf("\nTesting with the third element:\n");
    print_previous_elements(&arr[2]);  // Should print 30 (current), 20 (previous), and 10 (two back)

    printf("\nTesting with the first element:\n");
    print_previous_elements(&arr[0]);  // Should print 10 (current), warning for previous and two back

    return 0;
}


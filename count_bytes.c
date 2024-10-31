#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);  // Print each byte in hex format
    printf("\n");
}

void show_int(int x) {
    printf("Integer %d in bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    printf("Float %.2f in bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    printf("Pointer %p in bytes: ", x);
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main() {
    int int_value = 12345;
    float float_value = 123.45;
    int *pointer_value = &int_value;

    printf("Testing show_bytes function with different data types:\n\n");

    // Display the byte representation of an integer
    show_int(int_value);
    
    // Display the byte representation of a float
    show_float(float_value);
    
    // Display the byte representation of a pointer
    show_pointer(pointer_value);

    return 0;
}


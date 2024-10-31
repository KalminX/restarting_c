#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int arr1[5] = {1, 2, 3, 4, 6};
    printf("arr1[4] before: %d\n", arr1[4]);
    arr[-2] = 42;

	for (int i = 0; arr1[i] != '\0'; i++)
		printf("\narr1[%d] is %d\n", i, arr1[i]);
    printf("arr1[4] after: %d\n", arr1[4]);
    return 0;
}

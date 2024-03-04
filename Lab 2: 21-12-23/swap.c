#include <stdio.h>

void main() {
    int a, b;
    
    printf("Name: Priyanshu Kumar USN: 1BM22CS210\n");

    printf("Enter values of a & b:\n");
    scanf("%d %d", &a, &b);

    printf("Before swapping:\n");
    printf("a = %d & b = %d\n", a, b);

    swap(&a, &b);
    printf("\nAfter swapping:\n");
    printf("a = %d & b = %d\n", a, b);
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

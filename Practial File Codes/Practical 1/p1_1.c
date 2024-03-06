// To write a C program to implement Call by value

#include <stdio.h>

int swap(int p, int q) 
{
    printf("\nValues after swapping in SWAP function:-\n");
    int temp= p;
    p = q;
    q = temp;
    printf("a = %d\t b = %d", p, q);
}

int main()
{
    int a, b;
    printf("Enter 1st number: ");
    scanf("%d", &a);
    printf("Enter 2nd number: ");
    scanf("%d", &b);
    printf("Original values before swapping:-\n");
    printf("a = %d\t b = %d", a, b);
    swap(a, b);
    printf("\nValues after swapping in main function:-\n");
    printf("a = %d\t b = %d", a, b);
    return 0;
}

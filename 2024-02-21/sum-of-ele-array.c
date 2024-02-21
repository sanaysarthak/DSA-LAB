// Program in C to dynamically allocate memory at runtime using either malloc() or calloc(), and then find the sum of the elements of the array
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Allocating memory dynamically using calloc()
    int *ptr = (int*)malloc(n * sizeof(int));
    if(ptr != NULL)
        printf("Memory allocated dynamically at runtime by calloc()\n");

    // Taking elements as input from the user, and finding its sum
    int sum = 0;
    printf("\nEnter elements of Array:- \n");
    for(int i=0; i<n; i++) 
    {   
        printf("Enter element at index %d: ", i);
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }

    // Printing the output
    printf("\nSum of elements of Array = %d", sum);

    return 0;
}

#include <stdio.h>

int main() {

    // taking the size of array as input from the user
    int size;
    printf("Enter size of Array : ");
    scanf("%d", &size);

    //declaring the array
    int arr[size];

    // input the elements of the array
    printf("\nInput the elements:-\n");
    for(int i=0; i<size; i++)
    {
        printf("Enter element at index %d : ", i);
        scanf("%d", &arr[i]);
    }

    //printing the elements of the array in the reverse order
    printf("\nElements of the array in reverse order are :-\n");
    for(int i=size-1; i>=0; i--)
    {
        printf("%d\n", arr[i]);
    }   

    return 0;
}

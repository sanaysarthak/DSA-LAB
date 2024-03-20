// User defined variable sized Array Rotation program in C

#include <stdio.h>
int main() 
{
    int size, rot;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements of array :- \n");
    for(int i=0; i<size; i++)
    {
        printf("Enter element at index %d : ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter no. of rotations: ");
    scanf("%d", &rot);
    
    printf("\nThe original array is :-\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int temp=0; // initializing temp variable as 0
    for(int i=0; i<rot; i++)
    {
        temp = arr[0];
        for(int j=0; j<size-1; j++)
        {
            arr[j] = arr[j+1];
        }
        arr[size-1] = temp;
        printf("\nAfter Rotation %d:-\n", i+1);
        for(int k=0; k<size; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    return 0;
}

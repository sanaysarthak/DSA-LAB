// Program in C to reverse the elements of an array
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d", &arr[i]);
    }
  
    printf("Original Array:-\n");
    for(int i=0; i<n; i++)
    {
        printf("%d  ", arr[i]);
    }
  
    // Reversing the Array
    for(int i=0, j=n-1; i<j; i++, j--)
    {
        int temp= arr[i];
        arr[i]= arr[j];
        arr[j]= temp;
    }
  
    printf("\nReverse of the Array:-\n");
    for(int i=0; i<n; i++)
    {
        printf("%d  ", arr[i]);
    }
  
    return 0;
}

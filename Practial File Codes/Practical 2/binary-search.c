// Program to perform the Binary Search Algorithm in C

// Note :- It only works with "sorted array".

/* startIndex represents the starting index
endIndex repsrents the ending index
Time complexity in worst case scenario is O(log N) base 2 or O(N/2) */

#include <stdio.h>

int binarySearch(int array[], int startIndex, int endIndex, int x)
{
  if (endIndex >= startIndex)  // used for checking if the position is at the extreme ends of the array or not
  {
    int mid = startIndex + (endIndex - startIndex) / 2;

    // If found at mid, then return it
    if(array[mid] == x)
      return mid;

    // Search the left half
    else if(array[mid] > x) 
      return binarySearch(array,  startIndex, mid - 1,x);

    // Search the right half
    else
        return binarySearch(array, mid + 1, endIndex, x);
  }
  return -1;
}

int main() 
{
    int size, ele;
    printf("Enter the size of an array: ");
    scanf("%d", &size);

    int arr[size];
    printf("\nEnter elements in the array :-\n");
    for(int i=0; i<size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter a number to search it in the array: ");
    scanf("%d", &ele);
    printf("Performing Binary Search algorithm to check whether the number is in the array or not.\n");
    
    int res = binarySearch(arr, 0, size-1, ele);
    if (res == -1)
        printf("\nThe number %d is not in the Array.", ele);
    else 
        printf("\nThe number %d is present at index %d.", ele, res);
    
    return 0;
}

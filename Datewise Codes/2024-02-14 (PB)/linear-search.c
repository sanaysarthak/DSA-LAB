// Program to perform the linear Search Algorithm in C

/* Time Complexity :-
O(N) is read as Order of N
Worst case scenario : O(N)
Average case scenario : O(N/2)
Best case scenario : O(1)*/

#include <stdio.h>

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements in the array :-\n");
    for(int i=0; i<size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &arr[i]);
    }

    int ele, flag= 0;
    printf("\nEnter a number : ");
    scanf("%d", &ele);
    printf("Performing Linear Search algorithm to check whether the number is in the array or not.\n");
    for(int i=0; i<size; i++)
    {
        if(ele == arr[i])
        {
            printf("\nThe number %d is present at index %d.", ele, i);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("\nThe number %d is not in the Array.", ele);

    return 0;
}

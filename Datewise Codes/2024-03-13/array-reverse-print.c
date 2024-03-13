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

// Sample output in the terminal
/*
Enter size of Array : 5

Input the elements:-
Enter element at index 0 : 10
Enter element at index 1 : 20
Enter element at index 2 : 30
Enter element at index 3 : 40
Enter element at index 4 : 50

Elements of the array in reverse order are :-
50
40
30
20
10
*/

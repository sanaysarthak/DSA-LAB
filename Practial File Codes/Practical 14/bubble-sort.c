// Program in C to perform Bubble Sort Algorithm
// Sorting in Ascending order

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int size) {
    // Bubble Sort Algorithm
    for(int i=0; i<size; i++) {
        for(int j=0; j<size-1; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void print_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main() {
    
    // intializing the array
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements of the array:-\n");
    for(int i=0; i<size; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe original array is:-\n");
    print_array(arr, size);

    // Performing Bubble Sort on the given array
    bubble_sort(arr, size);
    
    printf("\n\nSorted array after applying Bubble Sort Algorithm:-\n");
    print_array(arr, size);
    
    return 0;
}

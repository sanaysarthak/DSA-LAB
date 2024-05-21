// NOT WORKING -> FIX IT

// Program in C to perform Selection Sort Algorithm
// Sorting in Ascending order

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int arr[], int size) {
    // Selection Sort Algorithm
    for(int i=0; i<size; i++) {
        int min = i;
        for(int j=i; j<size; j++) {
            if(arr[j] < arr[min]) 
                min = j;
        }
        if(min != i)
            swap(&arr[i], &arr[min]);
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

    // Performing Selection Sort on the given array
    selection_sort(arr, size);

    printf("\n\nSorted array after applying Selection Sort Algorithm:-\n");
    print_array(arr, size);

    return 0;
}

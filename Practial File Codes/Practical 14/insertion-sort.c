// Program in C to perform Insertion Sort Algorithm
// Sorting in Ascending order

#include <stdio.h>

void insert_elements(int arr[], int size) {
    printf("\nEnter elements in the array:-\n");
    for(int i=0; i<size; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void insertion_sort(int arr[], int size) {
    // starting from index 1, because index 0 by default is said to be sorted
    for(int i=1; i<size; i++) {
        int key = arr[i];
        int j = i - 1;
        while((j >= 0) && (key < arr[j])) { // Moving the elements greater than key to one position ahead from their current position
            arr[j+1] = arr[j];
            j = j - 1; // decrementing
        }
        arr[j+1] = key; // filling the original j value, but writing j+1 as we did decrement
    }
}

void print_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    insert_elements(arr, size);

    printf("\nOriginal Array is:-\n");
    print_array(arr, size);

    printf("\n\nArray after performing Insertion sorting:-\n");
    insertion_sort(arr, size);
    print_array(arr, size);
    return 0;
}

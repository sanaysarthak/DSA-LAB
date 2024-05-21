// Program in C to perform Insertion Sort Algorithm
// Sorting in Ascending order

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertion_sort(int arr[], int size) {
    // Insertion Sort Algorithm
    for(int i=0; i<size; i++) {
        int j = i;
        while(j>0 && arr[j] < arr[j-1]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

void print_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main() {
    // initializing the array
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

    // Performing Insertion Sort on the given array
    insertion_sort(arr, size);

    printf("\n\nSorted array after applying Insertion Sort Algorithm:-\n");
    print_array(arr, size);

    return 0;
}

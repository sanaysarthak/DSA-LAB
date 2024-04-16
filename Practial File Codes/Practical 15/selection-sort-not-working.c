// NOT WORKING -> FIX IT

// Program in C to perform Selection Sort Algorithm
// Sorting in Ascending order

#include <stdio.h>

void insert_elements(int arr[], int size) {
    printf("\nEnter elements in the array:-\n");
    for(int i=0; i<size; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void selection_sort(int arr[], int size) {
    for(int i=0; i<size; i++) {
        int key = arr[i];
        int temp = key;
        int index = i;
        for(int j=i; j<size; j++) {
            if(arr[j] < temp) {
                temp = arr[j];
                index = i;
            }
        }
        arr[i] = temp;
        arr[index] = key;
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

    printf("\n\nArray after performing Selection sorting:-\n");
    selection_sort(arr, size);
    print_array(arr, size);
    return 0;
}

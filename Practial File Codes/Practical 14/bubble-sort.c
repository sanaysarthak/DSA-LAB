// Program in C to perform Bubble Sort Algorithm
// Sorting in Ascending order

#include <stdio.h>

void insert_elements(int arr[], int size) {
    printf("\nEnter elements in the array:-\n");
    for(int i=0; i<size; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void bubble_sort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    printf("\n\nArray after performing bubble sorting:-\n");
    bubble_sort(arr, size);
    print_array(arr, size);
    return 0;
}

// Program in C to implement Quick Sort Algorithm

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
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

    // Performing Quick Sort on the given array
    quick_sort(arr, 0, size-1);

    printf("\n\nSorted array after applying Quick Sort Algorithm:-\n");
    print_array(arr, size);
    
    return 0;
}

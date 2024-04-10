// Program in C to perform Array Rotation, by taking user defined inputs for array and rotation

#include <stdio.h>

int main() {
	int size;
	printf("Enter size of array: ");
	scanf("%d", &size);

	int arr[size];
	printf("\nEnter elements of the array:-\n");
	for(int i=0; i<size; i++) {
		printf("Enter element at index %d : ", i);
		scanf("%d", &arr[i]);
	}

	printf("\nThe original array:-\n");
	for(int i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}

	int rot, temp;
	printf("\n\nEnter no. of rotations: ");
	scanf("%d", &rot);
	for(int i=1; i<=rot; i++) {
		temp = arr[0];
		for(int j=0; j<size-1; j++) {
			arr[j] = arr[j+1];
		}
		arr[size-1] = temp;
	}

	printf("\nArray after %d rotations:-\n", rot);
	for(int i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}

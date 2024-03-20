// 10 20 30 40 50 60
// Rot1: 20 30 40 50 60 10
// Rot2: 30 40 50 60 10 20
// Rot3: 40 50 60 10 20 30

#include <stdio.h>
int main() 
{
    int size = 6;
    int arr[6] = {10, 20, 30, 40, 50, 60};
    
    int temp=0;
    int rot = 3;
    for(int i=0; i<rot; i++)
    {
        temp = arr[0];
        for(int j=0; j<size-1; j++)
        {
            arr[j] = arr[j+1];
        }
        arr[size-1] = temp;
        printf("\nAfter Rotation %d:-\n", i+1);
        for(int k=0; k<size; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    return 0;
}

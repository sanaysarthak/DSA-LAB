#include <stdio.h>
int main() 
{
    int arr[7] = {3, 1, 3, 1, 2, 3, 1};
    int count[7] = {0};
    for(int i=0; i<7; i++)
    {
        count[arr[i]]++;
    }
    for(int i=0; i<7; i++)
    {
        if(count[arr[i]] > 1)
        {
            printf("%d\n", arr[i]);
            count[arr[i]] = 0;
        }
    }
    return 0;
}

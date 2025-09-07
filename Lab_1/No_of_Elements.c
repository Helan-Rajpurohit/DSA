//Number of elements in an array
#include <stdio.h>

int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Variable Length Array (VLA)

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("The number of elements in the array is: %d\n", n);

    return 0;
}
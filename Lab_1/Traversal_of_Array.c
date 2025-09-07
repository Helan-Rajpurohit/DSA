//Traversal of Array
#include <stdio.h>

int main() 
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  // VLA (variable length array in C99)

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are: ");
    for(i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
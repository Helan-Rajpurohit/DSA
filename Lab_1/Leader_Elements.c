//Leader Elements in Array
#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) 
    {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[100], leaders[100];
    int i, j = 0;

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int max_from_right = arr[n - 1];
    leaders[j++] = max_from_right;

    for (i = n - 2; i >= 0; i--) 
    {
        if (arr[i] > max_from_right)
         {
            max_from_right = arr[i];
            leaders[j++] = max_from_right;
        }
    }

    // Reverse the leaders array to print in original order
    printf("Leader elements are: ");
    for (i = j - 1; i >= 0; i--) 
    {
        printf("%d ", leaders[i]);
    }

    return 0;
}
//Smallest Element in Array
#include <stdio.h>

int main() 
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) 
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0];
    for(int i = 1; i < n; i++) 
    {
        if(arr[i] < min) 
        {
            min = arr[i];
        }
    }

    printf("The smallest element is: %d\n", min);

    return 0;
}
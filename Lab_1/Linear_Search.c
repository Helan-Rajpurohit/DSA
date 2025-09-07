//Linear Search in Array
#include <stdio.h>

int main() 
{
    int n, key, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) 
    {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[100];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
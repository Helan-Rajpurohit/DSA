//Insert Element at given Position
#include <stdio.h>

int main() 
{
    int n, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n >= 100 || n < 0) 
    {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[100];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    printf("Enter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) 
    {
        printf("Invalid position.\n");
        return 1;
    }

    for(int i = n; i > pos; i--) 
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;

    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
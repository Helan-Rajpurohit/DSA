//Delete Element from given position
#include <stdio.h>

int main() 
{
    int n, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) 
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

    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) 
    {
        printf("Invalid position.\n");
        return 1;
    }

    for(int i = pos; i < n - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion:\n");
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
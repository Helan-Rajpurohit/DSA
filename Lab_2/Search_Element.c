#include <stdio.h>

int main() {
    int array[3][3][3];
    int i, j, k;
    int value, found = 0;

    // Input elements into 3D array
    printf("Enter elements for a 3x3x3 array:\n");
    for (i = 0; i < 3; i++) 
    {
        printf("\nLayer %d:\n", i);
        for (j = 0; j < 3; j++) 
        {
            for (k = 0; k < 3; k++) 
            {
                printf("array[%d][%d][%d]: ", i, j, k);
                scanf("%d", &array[i][j][k]);
            }
        }
    }

    // Input target value to search
    printf("\nEnter the element to search for: ");
    scanf("%d", &value);

    // Search for the target element
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            for (k = 0; k < 3; k++) 
            {
                if (array[i][j][k] == value) 
                {
                    printf("Element %d found at position (Layer=%d, Row=%d, Column=%d)\n", value, i, j, k);
                    found = 1;
                }
            }
        }
    }

    if (!found) 
    {
        printf("Element %d not found in the array.\n", value);
    }

    return 0;
}
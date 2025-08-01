#include <stdio.h>

int main() 
{
    int i,j,k;
    // Declare and initialize a 3D array [2][3][4]
    int array[2][3][4] = {
        {{1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}},

        {{13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}}};

    // Display all elements with their indices
    printf("Displaying all elements with indices:\n");
    for (i = 0; i < 2; i++) 
    {           // layers
        for (j = 0; j < 3; j++) 
        {       // rows
            for (k = 0; k < 4; k++) 
            {   // columns
                printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
            }
        }
    }

    // Display layer by layer
    printf("\nDisplaying elements layer by layer:\n");
    for (i = 0; i < 2; i++) 
    {
        printf("\nLayer %d:\n", i);
        for (j = 0; j < 3; j++) 
        {
            for (k = 0; k < 4; k++) 
            {
                printf("%d\t", array[i][j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
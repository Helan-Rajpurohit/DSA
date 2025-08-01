#include <stdio.h>

int main() {
    int array[2][2][2];
    int i, j, k , sum = 0;

    // Input elements
    printf("Enter 8 elements for a 2x2x2 array:\n");
    for (i = 0; i < 2; i++) // Layer
    {        
        for (j = 0; j < 2; j++) // Row
        {    
            for (k = 0; k < 2; k++) // Column
            { 
                printf("array[%d][%d][%d]: ", i, j, k);
                scanf("%d", &array[i][j][k]);
                sum += array[i][j][k]; 
            }
        }
    }

    // Print sum
    printf("\nSum of all elements = %d\n", sum);

    return 0;
}
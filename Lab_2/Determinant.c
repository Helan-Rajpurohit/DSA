#include <stdio.h>

int main() 
{
    int matrix[2][2], determinant;
    int i,j;

    // Input matrix elements
    printf("Enter elements of the 2x2 matrix:\n");
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // determinant calculation
    determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    // Display matrix
    printf("\nMatrix:\n");
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Print determinant
    printf("\nDeterminant of the matrix = %d\n", determinant);

    return 0;
}
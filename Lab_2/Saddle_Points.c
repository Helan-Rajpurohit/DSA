#include <stdio.h>

int main() 
{
    int i,j,k, rows,cols;
    int min_val,min_col;
    printf("Enter no. of  rows :");
    scanf("%d",&rows);
    printf("Enter no. of  columns :");
    scanf("%d",&cols);

    int matrix[rows][cols];

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int saddleFound = 0;

    // Check each row for saddle point
    for (i = 0; i < rows; i++) 
    {
         min_val = matrix[i][0];
         min_col = 0;

        // Find minimum element in the row
        for (int j = 1; j < cols; j++) 
        {
            if (matrix[i][j] < min_val) 
            {
                min_val = matrix[i][j];
                min_col = j;
            }
        }

        // Check if this element is maximum in its column
        int is_saddle = 1;
        for (k = 0; k < rows; k++) 
        {
            if (matrix[k][min_col] > min_val) 
            {
                is_saddle = 0;
                break;
            }
        }

        if (is_saddle) 
        {
            printf("\nSaddle Point Found: %d at position (%d, %d)\n", min_val, i, min_col);
            saddleFound = 1;
        }
    }

    if (!saddleFound) 
    {
        printf("\nNo Saddle Points Found in the Matrix.\n");
    }

    return 0;
}
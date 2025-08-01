#include <stdio.h>

int main() 
{
    int i,j, rows,cols;
    printf("Enter no. of  rows :");
    scanf("%d",&rows);
    printf("Enter no. of  columns :");
    scanf("%d",&cols);
    int Matrix[rows][cols], transpose[rows][cols];

    // Input matrix
    printf("Enter elements of Matrix \n ");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &Matrix[i][j]);
        }
    }

    // Transpose logic
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            transpose[j][i] = Matrix[i][j];
        }
    }

    // Print original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            printf("%d\t", Matrix[i][j]);
        }
        printf("\n");
    }

    // Print transposed matrix
    printf("\nTransposed Matrix:\n");
    for ( i = 0; i < cols; i++) 
    {
        for (j = 0; j < rows; j++) 
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
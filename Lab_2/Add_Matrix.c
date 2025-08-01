#include <stdio.h>

int main() 
{
    int i,j, rows,cols;
    printf("Enter no. of  rows :");
    scanf("%d",&rows);
    printf("Enter no. of  columns :");
    scanf("%d",&cols);
    int Matrix1[rows][cols], Matrix2[rows][cols], Result[rows][cols];

    // matrix1
    printf("Enter elements of Matrix 1\n ");
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &Matrix1[i][j]);
        }
    }

    
    // matrix2
    printf("Enter elements of Matrix 2 \n"); 
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &Matrix2[i][j]);
        }
    }

    // Add matrices
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            Result[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }

    // Print result
    printf("\nResultant Matrix after Addition:\n");
    for (i = 0; i <rows ; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            printf("%d\t", Result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
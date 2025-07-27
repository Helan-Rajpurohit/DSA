#include <stdio.h>

int main() 
{
    int rows, cols, i, j, isIdentity = 1;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows != cols) 
    {
        printf("Matrix is not square, so it cannot be an identity matrix.\n");
        return 0;
    }

    int matrix[rows][cols];
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            printf("Element [%d][%d]: ",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < cols; j++) 
        {
            if (i == j && matrix[i][j] != 1) 
            {
                isIdentity = 0;
                break;
            } else if (i != j && matrix[i][j] != 0) 
            {
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity)
        printf("The matrix is an identity matrix.\n");
    else
        printf("The matrix is not an identity matrix.\n");

    return 0;
}
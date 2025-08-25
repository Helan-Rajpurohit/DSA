#include <stdio.h>
int main()
{
    int i,j, row,col;
    printf("Enter no. of  rows :");
    scanf("%d",&row);
    printf("Enter no. of  columns :");
    scanf("%d",&col);

    //2D array declaration
    int arr[row][col];

    //elements input from user
    printf("Enter elements of Matrix ");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Element [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    
    //printing elements of matrix
    printf("Matrix is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("\t %d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;


}

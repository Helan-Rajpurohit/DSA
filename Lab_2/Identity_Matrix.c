#include <stdio.h>
int main()
{
    int arr[4][4]={0};
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j)
            {
                arr[i][j]=1;

            }
        }
    }
    printf("4x4 Identity Matrix\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("\t %d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;

}
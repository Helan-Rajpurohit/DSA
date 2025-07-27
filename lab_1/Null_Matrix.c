#include <stdio.h>
int main()
{
    int arr[3][3]={0};
    int i,j;
    printf("3x3 Null Matrix\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t %d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;

}
#include <stdio.h>
int main()
{
    // 3x3 array declaration & initialisation
    int arr[3][3]={{10,54,40},{25,40,39},{20,54,35}};
    
    int i,j;

    //print elements
    printf("3x3 Row Major Matrix\n");
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

#include<stdio.h>
#define size 100
int main()
{

    int arr[3][3]={{1,2,4},{3,5,8},{97,67,126}};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

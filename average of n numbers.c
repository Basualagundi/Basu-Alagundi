#include<stdio.h>
int main()
{
    int n;
    printf("enter n\n");
    float sum=0,avg=0;
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
        sum=sum+arr[i];
    }
    avg=sum/n;
    printf("%0.2f\n",avg);

}

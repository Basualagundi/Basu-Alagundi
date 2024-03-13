#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,sum=0;
    printf("enter n\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    float avg=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    avg=sum/n;
    printf("%0.2f\n",avg);

    free(arr);
}

#include<stdio.h>
int main()
{
    int num,val=1;
    printf("enter number\n");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        val=val*i;

    }
    printf("%d",val);

}

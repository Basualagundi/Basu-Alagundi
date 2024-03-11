#include<stdio.h>
#include <math.h>
int main()
{

    int rem,temp,num,sum=0;
    printf("enter number\n");
    scanf("%d",&num);
    temp=num;
    while(num!=0)
    {
        rem=num%10;
        sum=sum+pow(rem,3);
        num=num/10;
    }
    if(temp==sum)
    {
        printf("%d is armstrong number\n",temp);
    }
    else
        printf("%d is not an armstrong number\n",temp);
}

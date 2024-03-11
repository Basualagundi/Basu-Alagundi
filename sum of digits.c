#include<stdio.h>
int main()
{
    int rem,num,temp,sum=0;
    printf("enter number \n");
    scanf("%d",&num);
    temp=num;
    while(num!=0)
    {
        rem=num%10;
        sum=sum+rem;
        num=num/10;
    }
        printf("sum of digits is %d \n",sum);
    return 0;
}

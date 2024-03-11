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
        sum=sum*10+rem;
        num=num/10;
    }
        printf("%d is reversed number\n",sum);
    return 0;
}

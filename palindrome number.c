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
    if(temp==sum)
        printf("%d is palindrome number\n",temp);
    else
        printf("its not palindrome\n");
    return 0;
}

#include<stdio.h>
int main()
{
    int num1,num2,temp;
    printf("enter two numbers\n");
    scanf("%d%d",&num1,&num2);
    printf("%d %d\n",num1,num2);
    temp=num1;
    num1=num2;
    num2=temp;
    printf("%d %d",num1,num2);
    return 0;
}

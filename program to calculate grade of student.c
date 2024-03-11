#include<stdio.h>
int main()
{
    int marks;
    scanf("%d",&marks);
    if(marks>90&&marks<=100)
        printf("grade S");
    else if(marks>71&&marks<=90)
        printf("grade A");
     else if(marks>61&&marks<=70)
        printf("grade B");
     else if(marks>50&&marks<=60)
        printf("grade C");
     else if(marks>40&&marks<=50)
        printf("grade D");
     else if(marks>30&&marks<=40)
        printf("grade E");
     else
        printf("Fail");


}

#include<stdio.h>
void mark(int marks[]);
int largest_of_array(int marks[],int largest);
int minimum(int marks[],int min);
int main()
{
    int marks[]={98,97,86,84,95,100};
    int largest,min;
    mark(marks);
    largest=largest_of_array(marks,largest);
    min=minimum(marks,min);
    printf("largest_of_array is %d\n",largest);
    printf("minimum of array is %d\n",min);
    return 0;
}
void mark(int marks[])
{
    for(int i=0;i<6;i++)
    {
        printf("%d ",marks[i]);
    }
    printf("\n");

}
int largest_of_array(int marks[],int largest)
{
    largest=0;
    for(int i=0;i<6;i++)
    {
        if(largest<marks[i])
            largest=marks[i];
    }
   // printf("%d",largest);
    return largest;
}
int minimum(int marks[],int min)
{
    min=9999;
    for(int i=0;i<6;i++)
    {
        if(min>marks[i])
        {
            min=marks[i];
        }
    }
    return min;
}

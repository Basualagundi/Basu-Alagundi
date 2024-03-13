#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 typedef struct bus_details
{
    char bus_no[20],source[20],destination[20];
    int d_hr,d_min,r_hr,r_min,diff_hr,diff_min;
}brts;
void read_details(brts *bptr,int n)
{
    printf("Enter bus Details\n");
      for(int i=0;i<n;i++)
    {
        printf("Bus no. , Source, Destination,Departure time, Reaching time\n");
        scanf("%s%s%s%d%d%d%d",bptr->bus_no,bptr->source,bptr->destination,&bptr->d_hr,&bptr->d_min,&bptr->r_hr,&bptr->r_min);
        bptr++;
    }
}
void display_details(brts *bptr,int n)
{
     printf("Bus details are :\nBus no.\tSource\tDestn\tdep_time\tReach_time\tDuration\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%s\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\n",bptr->bus_no,bptr->source,bptr->destination,bptr->d_hr,bptr->d_min,bptr->r_hr,bptr->r_min,bptr->diff_hr,bptr->diff_min);
        bptr++;
    }

}
void search(brts *bptr,int n,char destn[20])
{
    if(strcmp(bptr->destination,destn)==0)
    {
        printf("%s\t%s\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\n",bptr->bus_no,bptr->source,bptr->destination,bptr->d_hr,bptr->d_min,bptr->r_hr,bptr->r_min,bptr->diff_hr,bptr->diff_min);
        bptr++;
    }
}
void duration(brts *bptr,int n)
{
    for(int i=0;i<n;i++)
    {
        bptr->diff_hr=bptr->r_hr-bptr->d_hr;
        bptr->diff_min=bptr->r_min-bptr->d_min;
        if(bptr->diff_min<0)
        {
            bptr->diff_min+=60;
            bptr->diff_hr--;
        }
        bptr++;
    }
}
int main()
{
    brts *bptr;
    int n;
    char destn[20];
    printf("enter the number of users\n");
    scanf("%d",&n);
    bptr=(brts*)malloc(n*sizeof(brts));
    read_details(bptr,n);
    display_details(bptr,n);
    scanf("%s",destn);
    search(bptr,n,destn);
    return 0;

}

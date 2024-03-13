#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bus_details{
    char bus_no[10],source[20],destination[20];
    int d_hr,d_min,r_hr,r_min,diff_hr,diff_min;
}BRTS;
void read_details(BRTS *bptr,int n)
{
    printf("Enter bus Details\n");
    printf("Bus no. , Source, Destination,Departure time, Reaching time\n");
    for(int i=0;i<n;i++)
    {
        scanf("%s%s%s%d%d%d%d",bptr->bus_no,bptr->source,bptr->destination,&bptr->d_hr,&bptr->d_min,&bptr->r_hr,&bptr->r_min);
        bptr++;
    }
}
void display_details(BRTS *bptr,int n){
    printf("Bus details are :\nBus no.\tSource\tDestn\tdep_time\tReach_time\tDuration\n");
    for(int i=0;i<n;i++){
        printf("%s\t%s\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\n",bptr->bus_no,bptr->source,bptr->destination,bptr->d_hr,bptr->d_min,bptr->r_hr,bptr->r_min,bptr->diff_hr,bptr->diff_min);
        bptr++;
    }
}
void compute(BRTS *bptr,int n){
    for(int i=0;i<n;i++)
    {
        bptr->diff_hr=bptr->r_hr - bptr->d_hr;
        bptr->diff_min=bptr->r_min - bptr->d_min;
        if(bptr->diff_min<0)
        {
            bptr->diff_hr--;
            bptr->diff_min+=60;
        }
        bptr++;
    }
}
void search(BRTS *bptr,int n,char bus[20]){
    int status=0;
    for(int i=0;i<n;i++){
        if(strcmp(bptr->bus_no,bus)==0){
            printf("%s\t%s\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\n",bptr->bus_no,bptr->source,bptr->destination,bptr->d_hr,bptr->d_min,bptr->r_hr,bptr->r_min,bptr->diff_hr,bptr->diff_min);
    }
        bptr++;
    }
    if(status==1)
        printf("%s\t%s\t%s\t%d:%d\t\t%d:%d\t\t%d:%d\n",bptr->bus_no,bptr->source,bptr->destination,bptr->d_hr,bptr->d_min,bptr->r_hr,bptr->r_min,bptr->diff_hr,bptr->diff_min);
    else
        printf("Bus not found\n");
}
int main(){
    BRTS *bptr;
    int n;
    char bus[20];
    printf("Enter no. of bus details\n");
    scanf("%d",&n);
    bptr=(BRTS*)malloc(n*sizeof(BRTS));
    read_details(bptr,n);
    compute(bptr,n);
    display_details(bptr,n);
    printf("Enter bus to search\n");
    scanf("%s",bus);
    search(bptr,n,bus);
    return 0;
}

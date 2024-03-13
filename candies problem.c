#include<stdio.h>
#include<stdlib.h>
struct jar
{
    int candies;
    struct jar *rlink;
    struct jar *llink;
};
struct jar *create_node()
{
    struct jar *newnode=(struct jar *)malloc(sizeof(struct jar));
    if(newnode==NULL)
        printf("Memory not allocated\n");
    else
    {
        printf("enter the number of candies\n");
        scanf("%d",&newnode->candies);
        newnode->rlink=NULL;
        newnode->llink=NULL;
    }
    return newnode;
}
struct jar *insert_end_dll(struct jar *head)
{
    struct jar *cur=head;
   struct jar* newnode=create_node();
   if(head==NULL)
    head=newnode;
   else
   {
       while(cur->rlink!=NULL)
       {
           cur=cur->rlink;

       }
       cur->rlink=newnode;
       newnode->llink=cur;
       newnode->rlink=NULL;
    }
    return head;

}
void eat_candies(struct jar *head,int k,int D)
{
    struct jar *cur=head;
    int alice=k/2;
    int bob=k/2;
    if(head==NULL)
        printf("list empty\n");
    while(head!=NULL)
    {
        head->candies=head->candies-D;
        head=head->rlink;
    }
    cur=head;
    printf("candies left in alice jar is\n");
    for(int i=0;i<alice;i++)
    {
        printf("%d ",head->candies);
        head=head->rlink;
    }
    printf("candies left in bobs jar is \n");
    for(int i=0;i<bob;i++)
    {
        printf("%d ",head->candies);
        head=head->llink;
    }



}
int main()
{

    struct jar *head=NULL;
    int k,D;
    printf("enter the even number of jars\n");
    scanf("%d",&k);
    if(k%2==0)
    {
        for(int i=0;i<k;i++)
            head=insert_end_dll(head);
        //display_list(head);
        scanf("%d,&D");
        eat_candies(head,k,D);
    }
    else
        printf("number of jars should be even\n");
}

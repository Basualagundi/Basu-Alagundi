#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *create_node()
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  if(newnode==NULL)
  {
      newnode=NULL;
  }
  else
  {
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
  }
  return newnode;
}
int count_nodes(struct node *head)
{
    int count=0;
    struct node *cur=head;
    while(cur!=NULL)
    {
        cur=cur->link;
        count++;
    }
    return count;
}
struct node* insert_position(struct node *head,int pos)
 {
     struct node* cur=head,*next;
    struct node *newnode=create_node();
    int count=count_nodes(head);
   if(head==NULL&&pos==1)
   {
       head=newnode;
   }
   else if(pos==1)
   {
       newnode->link=head;
       head=newnode;
   }
   else if(pos==count+1)
   {
       struct node *cur=head;
       while(cur->link!=NULL)
       {
           cur=cur->link;
       }
       cur->link=newnode;
   }
   else if(pos>1&&pos<=count)
   {
      for(int i=1;i<pos-1;i++)
     {
        cur=cur->link;
        next=cur->link;
        cur->link=newnode;
        newnode->link=next;
     }
   }
   else if(pos>count+1)
    printf("invalid position\n");
   return head;
}

int main()
{
    struct node *head;
    int choice,pos,number;
    printf("1. create node 2.count nodes 3.insert position 4.exit\n");
    while(1)
    {
       printf("enter choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
          case 1:head=create_node();
          break;
          case 2:number=count_nodes(head);
                 printf("number of nodes %d\n",number);
          break;
          case 3:printf("enter position\n");
                 scanf("%d",&pos);
                 head=insert_position(head,pos);
                 printf("inserted position at %d\n",head->data);
                 break;
          case 4:exit(0);
                 break;
          default:
            printf("invalid input\n");
       }
       struct node *cur=head;
            while (cur!=NULL)

            {
                printf("%d\n",cur->data);
                cur=cur->link;
            }

    }


    return 0;
}

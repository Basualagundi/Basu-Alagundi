#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *create_node()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
       return NULL;
    else
    {
        scanf("%d",&newnode->data);
        newnode->link=newnode;
    }
    return newnode;
}
struct node *insert_front_csll(struct node *head,struct node *newnode)
{
    struct node *cur=head;
    if(head==NULL)
    return NULL;
    else
    {
        while(cur->link!=head)
        cur=cur->link;
        cur->link=newnode;
        newnode->link=head;
        head=newnode;

    }
    return head;
}
void display_csll(struct node *head)
{
    struct node *cur=head;
    if(head==NULL)
    printf("empty.\n");
    else
    {
        do
        {
            printf("%d",cur->data);
            cur=cur->link;
        }
        while(cur!=head);
    }
}
int count_nodes(struct node *head)
{
    int cnt=0;
    struct node *cur=head;
    while(cur->link!=head)
    {
        cur=cur->link;
        cnt++;
    }
   return cnt;
}
struct node *insert_position(struct node *head,int p,struct node *newnode)
{
    int count=count_nodes(head);
    struct node *cur=head;
    if(head==NULL)
    return NULL;
    else if(p<=1)
    {
        while(cur->link!=head)
            cur=cur->link;

       cur->link=newnode;
       newnode->link=head;
       head=newnode;

    }
    else if(p>=count+1)
    {
        while(cur->link!=head)
            cur=cur->link;
        cur->link=newnode;
        newnode->link=head;
    }
    else if(p>1&&p<=count)
    {
        for(int i=1;i<p-1;i++)
        {

            cur=cur->link;
        }
        newnode->link=cur->link;
        cur->link=newnode;
    }
    return head;
}
struct node *delete_position(struct node *head,int q)
{
    int count=count_nodes(head);
    struct node *cur=head,*prev=head,*temp=head;
    if(head==NULL)
        return NULL;
    else if(head->link==head&&q==1)
    {
        free(head);
        head=NULL;
    }
    else if(q<=1)
    {
        while(cur->link!=head)
        {
            cur=cur->link;
        }
        cur->link=head->link;
        head=head->link;
        free(temp);

    }
    else if(q>=count)
    {
        while(cur->link!=head)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=head;
        free(cur);

    }
  else if(q>1&&q<count)
  {
      for(int i=1;i<q;i++)
      {
          prev=cur;
          cur=cur->link;
      }
      prev->link=cur->link;
      free(cur);
  }
    return head;
}
int main()
{
struct node *head=NULL,*newnode=NULL;
    int n,p,q;
    scanf("%d",&n);
    if(n>=1)
    {
        for(int i=0;i<n;i++)
        {
           newnode=create_node();
           insert_front_csll(head,newnode);
        }
        printf("Circular list is:");
        display_csll(head);
        scanf("%d",&p);
        printf("Circular list after insertion is:\n");
        head=insert_position(head,p,newnode);
        display_csll(head);
        scanf("%d",&q);
        printf("Circular list after deletion is:\n");
        head=delete_position(head,q);
        display_csll(head);

    }
    else
        printf("Invalid input\n");
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct car
{
    char trn[20],c_owner[20],c_name[20];
    struct car *link;
}*NODE;
NODE create_node()
{
    NODE newn=(NODE)malloc(sizeof(struct car));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        printf("Enter node data\nEnter Temporary R no,Car owner,Car name\n");
        scanf("%s%s%s",newn->trn,newn->c_owner,newn->c_name);
        newn->link=NULL;
    }
    return newn;
}
NODE insert_f(NODE head)
{
    NODE newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
void display(NODE head)
{
    if(head==NULL)
        printf("Display error:SLL is empty\n");
    else
    {
        NODE cur=head;
        printf("Temp no\tCar owner\tCar name\n");
        while(cur!=NULL)
        {
            printf("%s\t%s\t%s\n",cur->trn,cur->c_owner,cur->c_name);
            cur=cur->link;
        }
    }

}
NODE delete_f(NODE head)
{
    if(head==NULL)
        printf("List is empty\n");
    else if(head->link==NULL)
    {
        printf("Deleted %s->%s->%s\n",head->trn,head->c_owner,head->c_name);
        free(head);
        head=NULL;
    }
    else
    {
        NODE cur=head;
        head=cur->link;
        printf("Deleted %s->%s->%s\n",cur->trn,cur->c_owner,cur->c_name);
        free(cur);
    }
    return head;
}
NODE delete_e(NODE head)
{
    NODE prev=NULL;
        NODE cur=head;
    if(head==NULL)
        printf("Sll is empty\n");
    else if(head->link==NULL)
    {
        printf("Deleted %s->%s->%s\n",head->trn,head->c_owner,head->c_name);
        free(head);
        head=NULL;
    }
    else
    {

        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("Deleted %s->%s->%s\n",cur->trn,cur->c_owner,cur->c_name);
        free(cur);
        prev->link=NULL;
    }
    return head;
}
int count(NODE head)
{
    int flag=0;
    if(head==NULL)
    {
        printf("Sll is empty\n Count 0\n");
    }
    else
    {
        NODE cur=head;
        while(cur!=NULL)
        {
            flag++;
            cur=cur->link;
        }
        printf("Registration issued is:%d\n",flag);
    }
}
void search(NODE head)
{
    char key[20];
    int status=0;
    NODE cur=head;
    printf("Enter number to search\n");
    scanf("%s",key);
    if(head=NULL)
    {
        printf("SLL is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(strcmp(cur->trn,key)==0)
            {
                status=1;
                break;
            }
            cur=cur->link;
        }
    }
    if(status==0)
    {
        printf("Search unsuccessful: Reg no not found\n");
    }
    else if(status==1)
    {
        printf("Search successful:%s->%s->%s\n",cur->trn,cur->c_owner,cur->c_name);
    }
}
void o_search(NODE head)
{
    char key[20];
    if(head==NULL)
    printf("Sll is empty");
    else
    {
        NODE cur=head;
      printf("Enter owner to be searched\n");
      scanf("%s",key);
      while(cur!=NULL)
      {
          if(strcmp(cur->c_owner,key)==0)
          {
            printf("%s->%s->%s\n",cur->trn,cur->c_owner,cur->c_name);
          }
          cur=cur->link;
      }
    }
}
NODE insert_position(NODE head,int pos)
{
   int i;
   NODE cur,next;
   NODE newnode=create_node();
   int cnt=count(head);
   if(head==NULL&&pos==1)//list is empty;
    head=newnode;
   else if (pos==1)//list is  not empty but insert at front;
   {
       newnode->link=head;
       head=newnode;
   }
   else if (pos==cnt+1)//list is not empty but insert at end;
   {
       cur =head;
       while(cur->link!=NULL)
        cur=cur->link;
       cur->link=newnode;
       //for(cur=head;cur->link!=NULL;cur=cur->link);
   }
   else if(pos>1&&pos<=cnt)
   {
       cur=head;
       for(int i=1;i<pos-1;i++)
       {
           cur=head;
           next=cur->link;
           cur->link=newnode;
           newnode->link=next;
       }
   }
   else if(pos>cnt+1)
   {
       printf("invalid input\n");

   }
   return head;

}
int main()
{
    NODE head=NULL;
    int ch,pos,cnt;

    printf("Singly LINKED List MENU\n");
    printf("Enter 1.insert at front 2.display 3.delete front 4.delete end 5.cnt 6.search 7.owner_serch 8. insert position\n");
    while(1)
    {
        printf("Enter the choice \n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:head=insert_f(head);
            break;
            case 2:display(head);
            break;
            case 3:head=delete_f(head);
            break;
            case 4:head=delete_e(head);
            break;
            case 5:cnt=count(head);
            break;
            case 6:search(head);
            break;
            case 7:o_search(head);
            break;
            case 8:printf("enter position\n");
            scanf("%d",&pos);
                insert_position(head,pos);

            break;
            case 9: exit(0);
            default:printf("Invalid input\n");
            break;
}
        }
        return 0;
}

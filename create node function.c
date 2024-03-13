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
  printf("memory not allocated\n");
  else
  {
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
  }
return newnode;

}
struct node *insert_front(struct node *head)
{
  struct node *newnode=create_node();
  if(head==NULL)
  {
      head=newnode;
  }
  else
  {
    newnode->link=head;
    head=newnode;

  }
  return head;
}
void display(struct node* head)
{
  struct node *cur;
  cur=head;
  while(cur!=NULL)
  {
      printf("%d\t",cur->data);
      cur=cur->link;
  }
  printf("\n");
}
struct node *insert_end(struct node *head)
{
  struct node* newnode=create_node();
  if(head==NULL)
  head=newnode;
  else
  {
      struct node *cur=head;
      while(cur->link!=NULL)
      {
          cur=cur->link;
      }
      cur->link=newnode;
  }
  return head;
}
struct node *delete_front(struct node *head)
{
  struct node *cur=NULL;
  cur=head;
  head=cur->link;
  free(cur);
  return head;
}
struct node *delete_end(struct node *head)
{
 struct node *cur=head,*prev;
 if(head==NULL)
 {
   printf("sll is empty\n");
 }
 else if(head->link==NULL)
 {
    free(head);
    head=NULL;
 }
 while(cur->link!=NULL)
 {
     prev=cur;
     cur=cur->link;
 }
 prev->link=NULL;
 free(cur);
 return head;

}

int main()
{
   struct node *head=NULL;
   printf("case1: create node case2: insert end case3: delete front case4: insert front case 5: delete end case 6: display case 7: exit \n ");
   int ch;
 while(1)
    {
      printf("enter choice\n");
      scanf("%d",&ch);
      switch(ch)
   {
      case 1: head=create_node();
      break;
      case 2: head=insert_end(head);
      break;
     case 3:
      printf("after deleting at front\n");
      head=delete_front(head);
      break;

      case 4:
      head=insert_front(head);
      printf("after deleting at end\n");
      break;
      case 5: delete_end(head);
      break;
      case 6:display(head);
      break;
      case 7:exit(0);
      break;
      default:printf("invalid input\n");
      break;
   }

   }



   return 0;
}

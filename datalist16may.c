#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *link;
} ;
typedef struct node *NODE;

NODE create_node()
{
        NODE newn=(NODE)malloc(sizeof(struct node));
        if(newn==NULL)
            printf("Error: Memory not allocated \n");
        else
        {
            printf("Enter data: ");
            scanf("%d",&newn->data);
            newn->link=NULL;
        }
        return newn;
}

NODE insert_end(NODE head)
{
    NODE newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
        NODE cur=head;
        while(cur->link != NULL)
            cur = cur->link;
        cur->link=newnode;
    }
    return head;
}

NODE insert_front(NODE head)
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

int count_nodes(NODE head)
{
        int count=0;
        if(head==NULL)
            return count;
        else
        {
                NODE cur=head;
                while(cur!=NULL)
                {
                        count++;
                        cur = cur->link;
                }
        }
        return count;
}

NODE insert_position(NODE head, int pos)
{
        NODE newnode = create_node();
        int count = count_nodes(head);
        //SLL empty
        if(count==0) // or if(head==NULL)
            head=newnode;
        else if(pos == 1) // first node
        {
                newnode->link=head;
                head=newnode;
        }
        else if(pos == count+1) // last node
        {
                NODE cur=head;
                while(cur->link != NULL)
                        cur = cur->link;
                cur->link = newnode;
        }
        else if(pos > count+1) // pos is more than count of nodes
                printf("Position entered is greater than nodes count in list\n");
        else if(pos> 1 && pos<=count) // pos is in the middle of list
        {
                NODE cur=head;
                for(int i=1; i<pos-1; i++)
                    cur = cur->link;
                newnode->link = cur->link;
                cur->link = newnode;
        }
        return head;
}

NODE delete_position(NODE head, int pos)
{
        int count = count_nodes(head);
        // empty list.
        if(count == 0)
                printf("Delete position error: List empty.\n");
        else if(pos == 1 && head->link == NULL) // single node
        {
                printf("Deleted %d.\n", head->data);
                free(head);
                head = NULL;
        }
        else if(pos == 1) // multiple nodes, but first node to delete
        {
                NODE cur=head;
                printf("Deleted %d\n", cur->data);
                head = head->link;
                free(cur);
        }
        else if(pos == count) // last node to delete
        {
                NODE last, cur=head;
                while(cur->link->link != NULL)
                        cur = cur->link;
                last = cur->link;
                printf("Deleted %d.\n", last->data);
                cur->link = NULL;
                free(last);
        }
        else if(pos>1 && pos<count) // middle node to delete
        {
                NODE next, cur=head;
                for(int i = 1; i<pos-1; i++)
                        cur = cur->link;
                next = cur->link;
                cur->link = next->link;
                printf("Deleted %d.\n", next->data);
                free(next);
        }
        else // pos is more than number of nodes.
            printf("Delete position error: Invalid position.\n");
        return head;
}

NODE delete_end(NODE head)
{
        if(head==NULL)
            printf("Delete End Error: List empty \n");
        else if(head->link == NULL)
        {
                printf("Deleted %d.\n", head->data);
                free(head);
                head=NULL;
        }
        else
        {
                NODE last, cur=head;
                while(cur->link->link !=NULL)
                        cur=cur->link;
                last = cur->link;
                printf("Deleted %d.\n", last->data);
                free(last);
                cur->link=NULL;
        }
        return head;
}

NODE delete_front(NODE head)
{
        if(head==NULL)
            printf("Delete front error: List empty \n");
        else if(head->link == NULL)
        {
                printf("Deleted %d \n", head->data);
                free(head);
                head=NULL;
        }
        else
        {
                NODE cur=head;
                printf("Deleted %d\n", cur->data);
                head = head->link;
                free(cur);
        }
        return head;
}

void display_list(NODE head)
{
    if(head==NULL)
        printf("Singly linked list empty.\n");
    else
    {
        printf("List is: \n");
        NODE cur=head;
        while(cur != NULL)
        {
                printf("%d ->", cur->data);
                cur  = cur->link;
        }
        printf("NULL\n");
    }
}

NODE insert_before(NODE head, int before)
{
        NODE newn = create_node();
        //empty SLL.
        if(head==NULL)
        {
                head=newn;
                printf("Insert_before: SLL empty, Inserted as head node\n");
        }
        //insert before first node, newnode becomes head node.
        else if(head->data == before)
        {
                newn->link = head;
                head = newn;
        }
        else
        {
                //any middle node in the SLL
                NODE prev=head, cur=head->link;
                while(cur != NULL)
                {
                        if(cur->data == before)
                        {
                                break;
                        }
                        prev = cur;
                        cur = cur->link;
                }
                if(cur == NULL)
                {
                        printf("Insert before Error: %d data not in list\n", before);
                }
                else
                {
                        prev->link = newn;
                        newn->link = cur;
                }
        }
        return head;
}

int main()
{
        int pos,before;
        NODE head=NULL;
        while(1)
        {
            printf("Menu. 1. Insert End 2. Insert front 3. Delete end 4. Delete front 5. Display 6. Count nodes 7. Ins pos 8. Del pos 9. Ins Before 10. Exit\n");
            printf("Enter your choice: ");
            int ch;
            scanf("%d",&ch);
            switch(ch)
            {
                    case 1: head = insert_end(head);
                                    printf("Insert end successful. \n");
                                    break;
                    case 2: head = insert_front(head);
                                    printf("Insert front successful. \n");
                                    break;
                    case 3: head = delete_end(head);
                                    break;
                    case 4: head = delete_front(head);
                                    break;
                    case 5: display_list(head);
                                    break;
                    case 6: printf("Number of nodes = %d. \n", count_nodes(head));
                                    break;
                    case 7: printf("Enter position to insert: ");
                                    scanf("%d",&pos);
                                    head = insert_position(head, pos);
                                    break;
                    case 8: printf("Enter position of node to delete: ");
                                    scanf("%d",&pos);
                                    head = delete_position(head, pos);
                                    break;
                    case 9: printf("Enter existing node data: ");
                                    scanf("%d", &before);
                                    head= insert_before(head, before);
                                    break;
                    case 10: exit(0);
                    default: printf("Invalid choice.\n");
                                    break;
            }
        }
        return 0;
}

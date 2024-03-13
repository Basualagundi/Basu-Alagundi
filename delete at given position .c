#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->link = NULL;
    }
    return newnode;
}

int count_nodes(struct node *head)
{
    int count = 0;
    struct node *cur = head;
    while (cur != NULL)
    {
        cur = cur->link;
        count++;
    }
    return count;
}

struct node *insert_position(struct node *head, int pos)
{
    struct node *cur = head, *next;
    struct node *newnode = create_node();
    int count = count_nodes(head);
    if (head == NULL && pos == 1)
    {
        head = newnode;
    }
    else if (pos == 1)
    {
        newnode->link = head;
        head = newnode;
    }
    else if (pos == count + 1)
    {
        struct node *cur = head;
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode;
    }
    else if (pos > 1 && pos <= count)
    {
        for (int i = 0; i < pos - 2; i++) // Stop at pos-2 to get to the previous node
        {
            cur = cur->link;
        }
        struct node *next = cur->link;
        cur->link = newnode;
        newnode->link = next;
    }
    return head;
}

struct node *delete_position(struct node *head, int pos)
{
    int count = count_nodes(head);
    struct node *cur = head, *prev;
    if (head == NULL && pos == 1)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        printf("Deleted data: %d\n", head->data);
        struct node *temp = head;
        head = head->link;
        free(temp);
    }
    else if (pos > 1 && pos <= count)
    {
        int i = 1;
        while (i < pos)
        {
            prev = cur;
            cur = cur->link;
            i++;
        }
        prev->link = cur->link;
        printf("Deleted data: %d\n", cur->data);
        free(cur);
    }
    else if (pos > count)
    {
        printf("Invalid position\n");
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    int choice, pos, number;
    printf("1. create node 2. count nodes 3. insert position 4. delete at position 5. exit\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create_node();
            break;
        case 2:
            number = count_nodes(head);
            printf("Number of nodes: %d\n", number);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = insert_position(head, pos);
            printf("Inserted data: %d\n", head->data);
            break;
        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            head = delete_position(head, pos);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
        }

        struct node *cur = head;
        while (cur != NULL)
        {
            printf("%d\n", cur->data);
            cur = cur->link;
        }
    }
    return 0;
}

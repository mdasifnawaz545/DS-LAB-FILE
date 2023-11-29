#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void push(int data);
void pop();
void IsEmpty();
void traverse();
int main()
{
    int choice, data;
    printf("Main Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. IsEmpty\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
    while (1)
    {
        printf("Enter Option : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Element to be pushed into the Stack : ");
            scanf("%d", &data);
            push(data);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            IsEmpty();
        }

        else if (choice == 4)
        {
            traverse();
        }
        else
            exit(1);
    }
    return 0;
}
void push(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else 
    {
        temp->next=start;
        start=temp;
    }
}
void pop()
{
    struct node *temp=start;
    if(start==NULL)
    {
        printf("Stack Empty : True.\n");
    }
    else {
        printf("%d Deleted from Stack\n",start->data);
        start=start->next;
        free(temp);
        temp=NULL;
    }
}
void IsEmpty()
{
    if(start==NULL)
    {
        printf("Stack Empty : True\n");
    }
    else
    {
        printf("Stack Empty : False\n");
    }
}
void traverse()
{
    struct node *temp=start;
    printf("Stack : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
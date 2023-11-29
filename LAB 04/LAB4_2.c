#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *start);
struct node *insert(struct node *start);
struct node *delete(struct node *start);
void display(struct node *start);
int count(struct node *start);
int main()
{
    struct node *start = NULL;
    int n;
    printf("Enter No. of Elements : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        start = create(start);
    }
    display(start);
    start = insert(start);
    display(start);
    start=delete(start);
    display(start);
    return 0;
}
void display(struct node *start)
{
    struct node *ptr = start;
    printf("Linked List is : ");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
}
int count(struct node *start)
{
    int co = 0;
    struct node *ptr = start;
    do
    {
        co++;
        ptr = ptr->next;
    } while (ptr != start);
    return co;
}
struct node *create(struct node *start)
{
    struct node *temp = malloc((sizeof(struct node)));
    struct node *ptr = NULL;
    int data;
    printf("Enter the data : ");
    scanf("%d", &data);
    temp->data = data;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        temp->next = start;
    }
    else
    {
        ptr = start;
        do
        {
            ptr = ptr->next;
        } while (ptr->next != start);

        temp->next = ptr->next;
        ptr->next = temp;
    }
    return start;
}
struct node *insert(struct node *start)
{
    int data;
    printf("\nEnter the data To Add: ");
    scanf("%d", &data);
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = start;
    temp->data = data;
    int pos;
    printf("Enter the Position : ");
    scanf("%d", &pos);
    int co;
    co = count(start);
    if (start == NULL)
    {
        start = temp;
        temp->next = start;
    }
    else if (pos > co + 1 || pos <= 0)
    {
        printf("Invalid Position.");
        exit(1);
    }
    else if (pos == 1)
    {
        do
        {
            ptr = ptr->next;
        } while (ptr->next != start);
        ptr->next = temp;
        temp->next = start;
        start = temp;
    }
    else
    {
        ptr = start;
        pos--;
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return start;
}
struct node *delete(struct node *start)
{
    int pos;
    struct node *ptr = start;
    printf("\nEnter the Position To Delete : ");
    scanf("%d", &pos);
    int co = count(start);
    if (pos > co || pos < 0)
    {
        printf("Invalid Position.");
        exit(1);
    }
    else if (pos == 1)
    {
        struct node *del = start;
        struct node *ptr = start;
              do
        {
            ptr = ptr->next;
        } while (ptr->next != start);
        del=start;
        start=start->next;
        ptr->next=start;
        free(del);
        del = NULL;
    }
    else
    {
        struct node *del = start;
        struct node *ptr = start;
        while (pos != 1)
        {
            ptr = del;
            del = del->next;
            pos--;
        }
        ptr->next = del->next;
        free(del);
        del = NULL;
    }
    return start;
}
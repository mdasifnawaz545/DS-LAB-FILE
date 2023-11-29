#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *start);
void search(struct node *start);
struct node *reverse(struct node *start);
struct node *sort(struct node *start);
void display(struct node *start);
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
    printf("Linked List is : ");
    display(start);
    search(start);
    start = sort(start);
    printf("\nSorted List is : ");
    display(start);
    start = reverse(start);
    printf("\nReverse List is : ");
    display(start);
    return 0;
}
struct node *create(struct node *start)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = start;
    int data;
    printf("Enter the Data : ");
    scanf("%d", &data);
    temp->data = data;
    if (start == NULL)
    {
        temp->next = NULL;
        start = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->next = NULL;
        ptr->next = temp;
    }
    return start;
}
void display(struct node *start)
{
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void search(struct node *start)
{
    struct node *ptr = start;
    int data;
    printf("\nEnter the Element To Find : ");
    scanf("%d", &data);
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("Element is Found.");
            break;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Element Not found.");
    }
}
struct node *reverse(struct node *start)
{
    struct node *ptr1 = NULL;
    struct node *ptr2 = NULL;
    while (start != NULL)
    {
        ptr2 = start->next;
        start->next = ptr1;
        ptr1 = start;
        start = ptr2;
    }
    start = ptr1;
    return start;
}
// struct node *sort(struct node *start)
// {
//     struct node *ptr = start;
//     struct node *ptr1 = NULL;
//     int temp;
//     while (ptr->next != NULL)
//     {
//         ptr1 = ptr->next;
//         while (ptr1 != NULL)
//         {
//             if (ptr->data > ptr1->data)
//             {

//                 temp = ptr->data;
//                 ptr->data = ptr1->data;
//                 ptr1->data = temp;
//             }
//             ptr1 = ptr1->next;
//         }
//         ptr = ptr->next;
//     }

//     return start;
// }

// new ascending node except the original node.

struct node *sort(struct node *start)
{
    struct node *new=malloc(sizeof(struct node));
    struct node *ptr1=start;
    struct node *ptr2=start->next;
    int temp;
    while (ptr1->next!=NULL)
    {
        ptr2=ptr1->next;
        while (ptr2!=NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    ptr1=start;
    return ptr1;
}

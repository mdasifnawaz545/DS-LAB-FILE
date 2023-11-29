#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
int count = 0;
void display(struct node *start);
struct node *addEmpty(struct node *start);
struct node *addEnd(struct node *start);
struct node *insert_certain(struct node *start);
struct node *insert_data(struct node *start);
struct node *delete_certain(struct node *start);
struct node *delete_data(struct node *start);
int count_nodes(struct node *start);
void traverse_list(struct node *start);

int main()
{
    struct node *start = NULL;
    struct node *ptr;
    printf("Create a List of 5 Nodes : \n");
    start = addEmpty(start);
    ptr = addEnd(start);
    ptr = addEnd(ptr);
    ptr = addEnd(ptr);
    ptr = addEnd(ptr);
    ptr = start;
    display(start);
    int option, a = 1;
    while (a)
    {
        printf("\n1. Insert a node at specific Position\n");
        printf("2. Insert after a given data\n");
        printf("3. Deletion of an element from specific Position\n");
        printf("4. Delete of a given data\n");
        printf("5. Count nodes\n");
        printf("6. Traverse the Linked List\n");
        printf("7. Exit\n");
        printf("Enter Your Option : ");
        scanf("%d", &option);
        if (option == 1)
        {
            start = insert_certain(start);
            display(start);
        }
        else if (option == 2)
        {
            start = insert_data(start);
            display(start);
        }
        else if (option == 3)
        {
            start = delete_certain(start);
            display(start);
        }
        else if (option == 4)
        {
            start = delete_data(start);
            display(start);
        }
        else if (option == 5)
        {
            int co;
            display(start);
            co = count_nodes(start);
            printf("\nNumber of Nodes are : %d", co);
        }
        else if (option == 6)
        {
            traverse_list(start);
        }
        else
        {
            exit(1);
        }
    }
    return 0;
}
struct node *addEmpty(struct node *start)

{
    int data;
    printf("Enter the Data : ");
    scanf("%d", &data);
    struct node *temp = malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;
    start = temp;
    return start;
}
struct node *addEnd(struct node *start)
{
    int data;
    printf("Enter the Data : ");
    scanf("%d", &data);
    struct node *temp = malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;
    start->next = temp;
    return temp;
}
void display(struct node *start)
{
    printf("Linked List is : ");
    struct node *ptr = start;
    while (ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
}
struct node *insert_certain(struct node *start)
{

    int pos, val;
    struct node *ptr = start;
    struct node *temp = malloc(sizeof(struct node));
    printf("Enter the position : ");
    scanf("%d", &pos);
    int cnt;
    cnt = count_nodes(start);
    if (pos >= cnt + 2)
    {
        printf("Invalid Position.");
        exit(1);
    }
    printf("Enter the data : ");
    scanf("%d", &val);
    temp->value = val;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = ptr->next;
        start = temp;
    }
    else
    {
        pos--;
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    printf("Inserted.\n");
    return start;
}
struct node *insert_data(struct node *start)
{
    int pdata, val;
    printf("Enter the Position Data : ");
    scanf("%d", &pdata);
    printf("Enter the data : ");
    scanf("%d", &val);
    struct node *temp = malloc(sizeof(struct node));
    struct node *ptr = start;
    temp->value = val;
    temp->next = NULL;
    while (ptr->value != pdata)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Invalid Data.");
        exit(1);
    }
    temp->next = ptr->next;
    ptr->next = temp;
    temp = start;
    return start;
}
struct node *delete_certain(struct node *start)
{
    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    struct node *ptr = start;
    if (pos == 1)
    {
        struct node *del = ptr;
        ptr = del->next;
        free(del);
        del = NULL;
        start = ptr;
        return start;
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
        struct node *del = NULL;
        del = ptr->next;
        ptr->next = del->next;
        free(del);
        del = NULL;
        ptr = start;
        return start;
    }
}
struct node *delete_data(struct node *start)
{
    int pdata;
    printf("Enter the Position Data : ");
    scanf("%d", &pdata);
    struct node *ptr = start;
    struct node *ptr1 = NULL;
    while (ptr->value != pdata)
    {
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1->next = ptr->next;
    free(ptr);
    ptr = NULL;
    ptr1 = start;
    return start;
}
int count_nodes(struct node *start)
{
    int count=0;
    struct node *ptr = start;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
void traverse_list(struct node *start)
{
    struct node *ptr = start;
    printf("Linked List is : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
}
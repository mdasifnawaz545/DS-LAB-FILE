#include <stdio.h>
#include <stdlib.h>
#define M 10
int stack[M];
int top = -1;
void push(int data);
void pop();
int IsFull();
int IsEmpty();
void traverse();
int main()
{
    int choice, data;
    printf("Main Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
    while (1)
    {
    printf("Enter Option : ");
    scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Element to be Pushed into the Stack : ");
            scanf("%d", &data);
            push(data);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            int val;
            val = IsEmpty();
            if (val == 1)
            {
                printf("Stack Empty : True\n");
            }
            else
                printf("Stack Empty : False\n");
        }
        else if (choice == 4)
        {
            int val;
            val = IsFull();

            if (val == 1)
            {
                printf("Stack Full : True\n");
            }
            else
                printf("Stack Full : False\n");
        }
        else if (choice == 5)
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
    if (top == M - 1)
    {
        printf("Stack Full : True.\n");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Empty : True\n");
    }
    else
    {
        printf("%d Deleted from Stack\n", stack[top]);
        top--;
    }
}
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int IsFull()
{
    if (top == M - 1)
    {
        return 1;
    }
    else
        return 0;
}
void traverse()
{
    printf("Stack : ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
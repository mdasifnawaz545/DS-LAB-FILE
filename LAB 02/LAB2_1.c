#include <stdio.h>
#include <stdlib.h>
void insert_pos(int a[], int n);
void delete_pos(int a[], int n);
void search(int a[], int n);
void transverse(int a[], int n);
int main()
{
    int n;
    printf("Enter the no. of element : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter Elements : ");
    for (int i = 0; i < n; i++)
    {
        // printf("Enter %d element : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n**Menu**\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Linear Search\n");
    printf("4. Transverse\n");
    printf("5. Exit\n");
    int choice;
    while (1)
    {
        printf("\n");
        printf("Enter Option : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            insert_pos(a, n);
        }
        else if (choice == 2)
        {
            delete_pos(a, n);
        }
        else if (choice == 3)
        {
            search(a, n);
        }
        else if (choice == 4)
        {
            transverse(a, n);
        }
        else if (choice == 5)
        {
            exit(1);
        }
    }
    return 0;
}
void insert_pos(int a[], int n)
{
    int pos, e;
    n++;
    printf("Enter the position : ");
    scanf("%d", &pos);
    if (pos > n || pos < 0)
    {
        printf("Invalid Positon.");
        exit(1);
    }
    
    printf("Enter the element : ");
    scanf("%d", &e);
    for (int i = n; i > pos - 1; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos - 1] = e;
    printf("New Elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void delete_pos(int a[], int n)
{
    int pos;
    printf("Enter the position : ");
    scanf("%d", &pos);
    if (pos > n || pos < 0)
    {
        printf("Invalid Positon.");
        exit(1);
    }
    for (int i = pos - 1; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    printf("New Elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void search(int a[], int n)
{
    int e, flag = 0;
    printf("Enter the element : ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == e)
        {
            printf("Element is at %d position", i + 1);
        }
        else
            flag++;
    }
    if (flag == n)
    {
        printf("Element Not Found.");
    }
}
void transverse(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
    }
    printf("No.of elements is %d", count);
}
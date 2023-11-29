#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void dequeue(int *arr,int N);
void enqueue(int data,int *arr,int N);
void traverse(int *arr,int N);
void IsEmpty(int *arr,int N);
void IsFull(int *arr,int N);
int front = -1;
int rear = -1;
int main()
{
    int N;
    printf("Enter the size of Queue : ");
    scanf("%d",&N);
    int *arr=(int *)calloc(N,sizeof(int));
    printf("Main Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. IsEmpty\n");
    printf("4. IsFull\n");
    printf("5. Traverse\n");
    printf("6. Exit\n");
    while (1)
    {
        int choice;
        printf("Enter Option : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int data;
            printf("Enter Element : ");
            scanf("%d", &data);
            enqueue(data,arr, N);
        }
        else if (choice == 2)
        {

            dequeue(arr,N);
        }
        else if (choice == 3)
        {

            IsEmpty(arr,N);
        }
        else if (choice == 4)
        {

            IsFull(arr,N);
        }
        else if (choice == 5)
        {

            traverse(arr,N);
        }
        else
            exit(1);
    }
    return 0;
}
void traverse(int *arr,int N)
{
    printf("Queue : ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", *(arr+i));
        i++;
    }
    printf("%d", arr[rear]);
    printf("\n");
}
void enqueue(int data,int *arr,int N)
{
    if (rear == N - 1)
    {
        printf("Queue is Full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear++;
        arr[rear] = data;
    }
}
void dequeue(int *arr,int N)
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is Empty\n");
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("Element Deleted\n");
    }
    else
    {
        front++;
        printf("Element Deleted\n");
    }
}
void IsEmpty(int *arr,int N)
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
        printf("Queue is not Empty\n");
}
void IsFull(int *arr,int N)
{
    if (rear == N - 1)
    {
        printf("Queue is Full\n");
    }
    else
        printf("Queue is not Full\n");
}
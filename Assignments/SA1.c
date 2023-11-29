// Circular Queue.
#include<stdio.h>
#define M 10
int queue[M];
int front=-1;
int rear=-1;
void enqueue(int data);
void dequeue();
void display();
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
void enqueue(int data)
{
    if((rear+1)%M==front)
    {
        printf("Queue is Full.\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else {
        rear=(rear+1)%M;
        queue[rear]=data;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is Empty.\n");
    }
    else if(rear==front)
    {
        rear=front=-1;
    }
    else{
        front=(front+1)%M;
    }
}
void display()
{
    printf("Queue is : ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ",queue[i]);
    }
    
}
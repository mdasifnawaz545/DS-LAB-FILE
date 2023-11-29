#include <stdio.h>
#include <string.h>
#define M 20
int top = -1;
char infix[M];
char stack[M];
char postfix[M];
void inToPos();
void push(char data);
int precedence(char symbol);
char pop();
int IsFull();
int IsEmpty();
int main()
{
    printf("Enter Infix Expression : ");
    gets(infix);
    inToPos();
    printf("Postfix Expression is : ");
    puts(postfix);
    return 0;
}
void inToPos()
{
    char symbol, temp, j = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((temp = pop()) != '(')
            {
                postfix[j++] = temp;
            }
            break;
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while (!IsEmpty() && precedence(symbol) <= precedence(stack[top]))
            {
                temp = pop();
                postfix[j++] = temp;
            }
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
            break;
        }
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
    return 0;
        break;
    }
}
char pop()
{

    int val;
    val = stack[top];
    top--;
    return val;
}
void push(char data)
{
    top++;
    stack[top] = data;
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
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
        return 0;
}
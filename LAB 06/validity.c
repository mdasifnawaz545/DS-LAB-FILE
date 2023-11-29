#include <stdio.h>
#include <string.h>
#define M 20
void push(char exp);
char pop();
int validate(char exp[]);
int IsEmpty();
int checker(char a,char b);
char exp[M];
char stack[M];
int top = -1;
int main()
{
    printf("Enter the Expression : ");
    gets(exp);
    printf("Expression is : ");
    puts(exp);
    int bal;
    bal = validate(exp);
    if (bal == 1)
    {
        printf("Valid Expression.\n");
    }
    else
    {
        printf("Invalid Expression.\n");
    }
    return 0;
}

int IsEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else return 0;
}
void push(char exp)
{
    if(top==M-1)
    {
        printf("Stack Overflow.");
    }
    top++;
    stack[top]=exp;
}
char pop()
{
    int val=stack[top];
    top--;
    return val;
}
int validate(char exp[])
{
    char temp, symbol;
    for (int i = 0; i < strlen(exp); i++)
    {
        symbol = exp[i];
        if (symbol == '(' || symbol == '{' || symbol == '[')
        {
            push(symbol);
        }
        else if (symbol == ')' || symbol == '}' || symbol == ']')
        {
            if (IsEmpty())
            {
                printf("Right Brackets are more.\n");
                return 0;
            }
            else
            {
                int check;
                temp = pop();
                check = checker(temp, symbol);
                if (check==0)
                {
                    printf("Mismatched Brackets.\n");
                    return 0;
                }

            }
        }
    }
    if (IsEmpty())
    {
        return 1;
    }
    else
    {
        printf("Left Brackets are more.\n");
        return 0;
    }
}
int checker(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;

    if (a == '{' && b == '}')
        return 1;

    if (a == '[' && b == ']')
        return 1;

        return 0;
}

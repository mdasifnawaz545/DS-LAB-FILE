#include <stdio.h>
void compare(int *a, int *b);
int main()
{
    int a, b;
    printf("Enter 1st Number : ");
    scanf("%d", &a);
    printf("Enter 2nd Number : ");
    scanf("%d", &b);
    compare(&a, &b);
    return 0;
}
void compare(int *a, int *b)
{
    if (*a > *b)
    {
        printf("%d is Greater than %d.", *a, *b);
    }
    else if (*b > *a)
    {
        printf("%d is smaller than %d.", *a, *b);
    }
    else if(*b==*a)
    {
        printf("%d and %d are same.",*b,*a);
    }
}
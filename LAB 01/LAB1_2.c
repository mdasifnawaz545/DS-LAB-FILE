#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int sum(int *ptr, int n);
int Isprime(int n);
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d Element :", i + 1);
        scanf("%d", &ptr[i]);
    }
    int s = sum(ptr, n);
    printf("Sum = %d", s);
    free(ptr);
    return 0;
}
int sum(int *ptr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (Isprime(*(&ptr[i])))
        {
            sum = sum + *(&ptr[i]);
        }
    }
    return sum;
}
int Isprime(int n)
{
    int count = 0;
    if (n == 1)
    {
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return 1;
    }
    else
        return 0;
}
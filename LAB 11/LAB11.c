#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 50
int a[M];
void QuickSort(int array[], int lb, int ub);
int Partition(int array[], int lb, int ub);
void swap(int *a, int *b);
int main()
{
    int array[] = {7, 4, 3, 2, 9, 8};
    int size = sizeof(array) / sizeof(int);
    printf("Original Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    int lb = 0, ub = size - 1;
    QuickSort(array, lb, ub);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int Partition(int a[], int lb, int ub)

{
    int start, end, pivot;
    start = lb;
    end = lb;
    pivot = a[lb];
    do
    {
        while (pivot > a[start])
        {
            start++;
        }
        while (pivot < a[end])
        {
            end--;
        }
        if (start < end)
        {
            // swap(&a[start], &a[end]);
            int temp;
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }

    } while (start < end);
    int temp;
    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;
    return end;
}

void QuickSort(int a[], int lb, int ub)

{
    if (lb > ub)
    {
        int loc;
        loc = Partition(a, lb, ub);
        QuickSort(a, lb, loc - 1);
        QuickSort(a, loc + 1, ub);
    }
    int n = sizeof(a) / sizeof(int);
    printf("Sorted Array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
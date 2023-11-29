#include <stdio.h>
void InsertionSort(int array[], int size);
void insertionSort(int a[], int n);
void SelectionSort(int array[], int size);
void selectionSort(int a[], int n);
void QuickSort(int array[], int lb, int ub);
int Partition(int array[], int lb, int ub);
void swap(int *a, int *b);
void print(int a[], int n);
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
    // insertionSort(array, size);
    // selectionSort(array, size);
    QuickSort(array, lb, ub);
    // print(array,size);
    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int a[], int lb, int ub)
{
    int start, end, pivot;
    start = lb;
    end = lb;
    pivot = a[lb];
    while (start > end)
    {
        while (pivot > a[start])
        {
            start++;
        }
        while (pivot < a[end])
        {
            end--;
        }
        if (start > end)
        {
            swap(&a[start], &a[end]);
            int temp;
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }
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
void print(int a[], int n)
{
    printf("Sorted Array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void selectionSort(int a[], int n)
{
    int index;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[index] > a[j])
            {
                index = j;
            }
        }
        if (index != i)
        {
            int temp;
            temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
    printf("Sorted Array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void InsertionSort(int array[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    printf("Sorted Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
void SelectionSort(int array[], int size)
{
    int index, temp, ptr;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[index] > array[j])
            {
                index = j;
            }
        }
        printf("  %d   \n", index);
        if (index != i)
        {
            temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }
    printf("Sorted Array is : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

// Inertion Sort

void insertionSort(int a[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Sorted Array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
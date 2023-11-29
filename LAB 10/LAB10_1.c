/*WAP to take some integer numbers from the user. Store the numbers in an array.
Then sort the array by calling any sorting techniques in a menu-driven approach. 
Bubble sort
Selection sort
Insertion sort*/

#include <stdio.h>
#define N 50
void bubbleSort(int[], int size);
void selectionSort(int[], int size);
void insertionSort(int[], int size);
int main()
{
    int size;
    int arr[N];
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter the %d Elements : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Menu : \n");
    printf("Given Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d ");
    printf("\nSelect One Sorting Techniques\n");
    printf("1.Bubble Sort\n");
    printf("2.Selection Sort\n");
    printf("3.Insertion Sort\n");
    printf("Enter Your Choice\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        bubbleSort(arr, size);
    }
    else if (choice == 2)
    {
        selectionSort(arr, size);
    }
    else if (choice == 3)
    {
        insertionSort(arr, size);
    }
    else
        printf("Invalid choice run the program again");

    return 0;
}
void insertionSort(int arr[], int size)
{
int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selectionSort(int arr[], int size)
{
    int index;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }
        if (index != i)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }

    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
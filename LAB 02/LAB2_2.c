#include <stdio.h>
int n;
void count_non_zero(int m[n][n], int n);
void upper_matrix(int m[n][n], int n);
void Diagonal_not(int m[n][n], int n);
int main()
{
    printf("Enter the size of the square matrix : ");
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    printf("Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    count_non_zero(m, n);
    printf("\n");
    upper_matrix(m, n);
    printf("\n");
    Diagonal_not(m, n);
    printf("\n");

    return 0;
}
void count_non_zero(int m[n][n], int n)
{

    int nz = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] != 0)
            {
                nz++;
            }
            else
                z++;
        }
    }
    printf("No. of Non-Zero Element : %d", nz);
}
void upper_matrix(int m[n][n], int n)
{
    printf("Upper Traingular Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (j > i)
                printf("%d", m[i][j]);
            else
            {
                printf(" ");
            }
        }
        j++;
        printf("\n");
    }
}
void Diagonal_not(int m[n][n], int n)
{
    printf("Elements Just above and below the main diagonal: \n");

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf(" ");
            }
            else
            {
                printf("%d ", m[i][j]);
            }
        }
        printf("\n");
    }
}
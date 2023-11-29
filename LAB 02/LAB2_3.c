#include <stdio.h>
int r, c;
void sparse(int m[r][c], int r, int c);
int main()
{
    printf("Enter the Size of Sparse Matrix : ");
    scanf("%d %d", &r, &c);
    int m[r][c];
    printf("Enter Elements of Sparse Matrix : ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    printf("Matrix : \n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    int nz;
    sparse(m, r, c);
    return 0;
}
void sparse(int m[r][c], int r, int c)
{
    int nz = 0, z = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (m[i][j] != 0)
            {
                nz++;
            }
            else
                z++;
        }
    }
    if (nz > z)
        printf("It is not a Sparse Matrix.");
    else
    {
        int k = 1;
        int sp[nz + 1][3];
        sp[0][0] = r;
        sp[0][1] = c;
        sp[0][2] = nz;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (m[i][j] != 0)
                {
                    sp[k][0] = i;
                    sp[k][1] = j;
                    sp[k][2] = m[i][j];
                    k++;
                }
            }
        }
        printf("Sparse Matrix in 3-Tuple Format : \n");
        for (int i = 0; i < nz + 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", sp[i][j]);
            }
            printf("\n");
        }
    }
}

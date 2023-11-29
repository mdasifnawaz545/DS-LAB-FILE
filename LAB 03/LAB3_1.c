#include <stdio.h>
int main()
{
    int row, column, nz;
    printf("Enter Sparse Matrix in 3-tuple format\n");
    scanf("%d %d %d", &row, &column, &nz);
    int sp[nz][3];
    for (int i = 0; i < nz; i++)
    {
        scanf("%d %d %d", &sp[i][0], &sp[i][1], &sp[i][2]);
    }
    int sp_transpose[nz][3];
    for (int i = 0; i < nz; i++)
    {

        sp_transpose[i][0] = sp[i][1];
        sp_transpose[i][1] = sp[i][0];
        sp_transpose[i][2] = sp[i][2];
    }
    printf("Transpose of Sparse Matrix \n");
    printf("R C Element\n");
    printf("%d %d %d\n", column, nz, nz);
    for (int i = 0; i < nz; i++)
    {
        printf("%d %d %d\n", sp_transpose[i][0], sp_transpose[i][1], sp_transpose[i][2]);
    }
    return 0;
}
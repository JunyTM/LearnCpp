#include <stdio.h>
#include <stdlib.h>
int print2DimC1(int *ar[3], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(*(ar + i) + j));
        }
        printf("\n");
    }
}
int print2DimC2(int ar[][3], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(*(ar + i) + j));
        }
        printf("\n");
    }
}
int print2DimC3(int **ar, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(*(ar + i) + j));
        }
        printf("\n");
    }
}
int print2DimC4(int (*ar)[3], int m, int n)
{

    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(*(ar + i) + j));
        }
        printf("\n");
    }
}
int main(void)
{
    int a1[][3] = {{0, 1, 2}, {3, 4, 5}}; // (A) true
    int a2[][3];                          // (B) true
    print2DimC1(a1, 2, 3);                // (C) false
    print2DimC2(a1, 2, 3);                // (D) true
    print2DimC3(a1, 2, 3);                // (E) false
    print2DimC4(a1, 2, 3);                // (F) true
    return 0;
}
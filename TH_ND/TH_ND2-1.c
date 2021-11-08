#include <stdio.h>
#include <stdlib.h>

// // bài 1
// void print1DimArr(int ar[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", ar[i]);
//     }
// }

// int print2DimArrA(int ar[][3], int m)
// {
//     int i, j;
//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < 3; j++)
//         {
//             printf("%d\t", ar[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// int print2DimArrB(int ar[][3], int m)
// {
//     int i, j;
//     for (i = 0; i < m; i++)
//     {
//         print1DimArr(ar[i], 3);
//         printf("\n");
//     }

//     return 0;
// }


// bài 2
void print1Dim(int *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(ar + i));
    }
}

int print2DimA(int *ar, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", *(ar + i * m + j));
        }
        printf("\n");
    }
    return 0;
}

int print2DimB(int *ar, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        print1Dim((ar + i * m), n);
        printf("\n");
    }
    return 0;
}

int main()
{
    int ar[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int exam1[3][3] = {{1, 2}, {4}, {5, 7}};
    // bài 1
    // print1DimArr(ar, 3);
    // print2DimArrA(ar , 3);
    // print2DimArrB(ar , 3);

    // bài 2
    // print1Dim(exam1, 3);
    // print2DimA(exam1, 3, 3);
    print2DimB(exam1, 3, 3);
    
    return 0;
}
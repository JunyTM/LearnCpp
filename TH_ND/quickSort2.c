#include <stdlib.h>
#include <stdio.h>

void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

int Part(int K[], int LB, int UB)
{
    int m = K[LB];
    int i = LB;
    int j = UB - 1;
    while (1)
    {
        while (i <= j && K[i] < m)
            i++;
        while (j >= i && K[j] > m)
            j--;

        if (i >= j) break;
        swap(K[i], K[j]);
        i++;
        j--;
        
    }
    swap(K[i], K[j]);
    return i;
}

void QuickSort(int K[], int LB, int UB)
{
    int j;
    if (LB < UB)
    {
        j = Part(K, LB, UB);
        QuickSort(K, LB, j - 1);
        QuickSort(K, j + 1, UB);
    }
}

void print_array(int k[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", k[i]);
    }
}

int main(void)
{

    int K[12] = {0, 42, 23, 74, 11, 65, 58, 94, 36, 99, 87, 30000};


    printf("\nMang truoc khi sap xep: ");
    print_array(K, 12);

    QuickSort(K, 0, 11);

    printf("\nMang sau khi sap xep: ");
    print_array(K, 12);
    return 0;
}

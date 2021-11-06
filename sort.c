#include <stdlib.h>
#include <stdio.h>

void selection_sort1(int k[], int n)
{
    int i, j, m, x;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (k[j] < k[m])
                m = j;
        }

        if (m != i)
        {
            // Thêm mã chương trình để đổi chỗ k[i] và k[m]
            x = k[i];
            k[i] = k[m];
            k[m] = x;                                           
        }
    }
}

void insert_sort1(int k[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = k[i];
        j = i - 1;
        while (x < k[j] && j >= 0)
        {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = x;
    }
}


void bubble_sort1(int k[], int n)
{
    int i, j, x;
    for (i = 1; i < n - 1; i++)
    {
        for (j = n - i - 1; j > i; j--)
        {
            if (k[j] < k[j - 1])
            {
                // Thêm mã chương trình để đổi chỗ k[j] và k[j-1];
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        }
    }
}


void printOut(int k[], int n){
    for(int i = 0; i<n; i++) {
        printf("%d ", k[i]);
    }
}



int main() {
    int n = 11;
    int a[] = {1,10,9,7,8,6,2,4,5,3,16};
    printOut(a, n);
    // selection_sort1(a, n);
    // insert_sort1(a, n);
    bubble_sort1(a, n);
    printf("\n");
    printOut(a, n);
}
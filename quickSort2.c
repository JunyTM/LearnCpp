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
    // Cho khai báo của hàm sắp xếp dãy số nguyên theo thứ tự tăng dần dùng giải thuật sắp xếp -
    // Quicksort.LB là chỉ số của phần tử đầu,

    // UB là chỉ số phần tử cuối của dãy cần sắp xếp.void QuickSort(int K[], int LB, int UB);
    // Cho khai báo hàm phân đoạn dãy K có chỉ số phần tử đầu là LB, chỉ số phần tử cuối là UB,
    // chọn phần tử chốt là phần tử đầu.Hàm trả về vị trí của phần tử chốt sau khi thực hiện phân
    // đoạn.

    int K[12] = {0, 42, 23, 74, 11, 65, 58, 94, 36, 99, 87, 30000};


    printf("\nMang truoc khi sap xep: ");
    print_array(K, 12);

    QuickSort(K, 0, 11);

    printf("\nMang sau khi sap xep: ");
    print_array(K, 12);
    return 0;
}

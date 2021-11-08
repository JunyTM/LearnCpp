#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Phân đống
void ADJUST(int K[], int i, int n) // i vị trí nút gốc, n số lượng nút
{
    int KEY = K[i];
    int j = 2 * i;
    while (j <= n)
    {
        if ( (j < n) && (K[j] < K[j+1]) ) j = j + 1;
        if (KEY > K[j])
        {
            K[j/2] = KEY;
            return;
        }
        K[j/2] = K[j];
        j = 2 * j ;
    }
    K[j/2] = KEY;
}

// Bug bỏ qua phần tử vị trí K[0]
void HeapSort(int K[], int n)
{
    int i;
    for (i = n/2 ; i >=1; i--)
        ADJUST(K, i, n);
    for (i = n - 1; i >= 1; i--)
    {
        int tmp = K[1];
        K[1] = K[i+1] ;
        K[i+1] = tmp;
        ADJUST(K, 1, i);
    }
}

// In ra mảng trừ phần tử đầu tiên 
void print_array(int k[], int n)
{
    int i;   
    for (i = 1; i < n; i++)
    {
        printf("%d ", k[i]);
    }
}
int main(void)
{
    int K[12]= {0,8,1,3,2,9,7,6,5,4,12,11};
    printf("\nMang truoc khi sap xep: ");
    print_array(K, 12); 
    HeapSort(K, 12);
    printf("\nMang sau khi sap xep: ");
    print_array(K, 12);
    return 0;
}

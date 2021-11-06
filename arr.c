#include <stdio.h>
#include <stdlib.h>

void viewArr1(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}
void viewArr2(int *arr, int len) {
    for(int i = 0; i < len; i++)
    {
        printf("%d ", *(arr + i));
    }
    
}

void viewArr2D(int *arr2, int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d\t", *(arr2 + i*x + j));
        }
        printf("\n");
    }
}

int main() {
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("mang 1 chieu:\n");
    viewArr1(arr, 12);
    // viewArr1(arr, 12);

    int arr2[3][4] = {{31,28,31,30},{31,30,31,30},{31,30,31,30}};
    printf("mang 2 chieu:\n");
    viewArr2D(arr2, 3, 4);
}
#include <stdio.h>
#include <stdlib.h>

// // Bai 1
// int main(void)
// {
//     int h[4] = {4, 5, 6};
//     printf("Gia tri cua h[0]=%d\n", h[0]);
//     printf("Gia tri cua h[4]=%d\n", h[3]);
//     printf("Dia chi cua h[0]=%p\n", h);     // Cach 1
//     printf("Dia chi cua h[0]=%p\n", &h[0]); // Cach 2
//     printf("Dia chi cua h[1]=%p\n", h + 1); // Cach 1
//     printf("Dia chi cua h[1]=%p\n", &h[1]); // Cach 2
//     printf("Gia tri cua h[1]=%d\n", h[1]);  // Cach 1
//     printf("Gia tri cua h[1]=%d\n", h[1]);  // Cach 2
//     return 0;
// }

// // Bai 2
// #define MTHS 12
// int main(void)
// {
//     int days[MTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int days2[MTHS] = {31, 28, 31, 30, 31, 30, 31};
//     int days3[] = {31, 28, 31, 30, 31, 30, 31};
//     printf("So luong phan tu cua days: %d\n", MTHS);
//     printf("So luong phan tu cua days2: %d\n", MTHS);
//     printf("So luong phan tu cua days3: %d\n", sizeof(days3) / sizeof(days3[0]));
//     printf("Gia tri cua phan tu days2[7]: %d\n", days2[7]);
//     printf("Gia tri cua phan tu days3[7]: %d\n", days3[7]);
//     return 0;
// }

// Bai 3
#define MTHS 12
int main(void)
{
    int i;
    int days[MTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("\nDUYET MANG: LIET KE GIA TRI CAC PHAN TU\n");
    for (i = 0; i < MTHS; i++)
        printf("Thang %d co %d ngay\n", i, days[i]);
}
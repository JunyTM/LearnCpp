#include <stdio.h>
#include <math.h>

/* Bug tạo đống sẽ bỏ qua phần từ K[0] ~ phần tử đầu tiền
=> Ta sẽ chỉ thao tác với n - 1 phần tử,
	duyệt từ phần tử thứ 2 trong mảng.
*/
void printArray(int K[], int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		printf("%d ", K[i]);
	}
}

void ADJUST(int K[], int i, int n) // i là chỉ số nút gốc, n là số nút của cây
{
	int KEY = K[i];
	int j = 2 * i; // j ghi nhận số thứ tự Nút Con Trái của i

	while (j <= n)
	{
		if ((j < n) && (K[j] < K[j + 1])) // tìm vịt trí nút còn phải (nút con lớn nhất) để so sánh với nút gốc(KEY)
			j = j + 1;

		if (KEY > K[j])
		{
			K[j / 2] = KEY; // khi xác định được vị trí của KEY => dừng lại
			return;
		}
		K[j / 2] = K[j]; // Nếu KEY nhỏ hơn khóa con => đưa khóa con lên

		j = 2 * j; // Tiếp tục đi xuống nhánh dưới để tìm vị trí cho KEY, vì KEY có thể nhỏ hợn nút ở nhánh này
	}
	K[j / 2] = KEY;
}

void HeapSort(int K[], int n)
{
	int i;
	// Tạo đống
	for (i = n / 2; i >= 1; i--)
	{
		ADJUST(K, i, n);
	}
	for (i = n - 1; i >= 1; i--)
	{
		// Đổi chỗ phần từ đầu với phần tử cuối
		int tmp = K[1];
		K[1] = K[i + 1];
		K[i + 1] = tmp;

		ADJUST(K, 1, i);
	}
}

int main()
{
	int K[] = {0, 9, 3, 6, 1, 4, 5, 7, 2, 8};
	int n = sizeof(K) / sizeof(int); // Kích thước mảng

	printf("Mang truoc khi sap xep: ");
	printArray(K, n);

	HeapSort(K, n);

	printf("\nMang sau khi sap xep: ");
	printArray(K, n);
}
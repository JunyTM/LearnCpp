#include<stdio.h>
#include<math.h>

void ADJUST(int K[],int i,int n){
	int KEY = K[i];
	int j=2*i;
	while(j<=n){
		if((j<n)&&(K[j] < K[j+1])) j = j+1;
		if(KEY > K[j]){
			K[floor(j/2)] = KEY;
			return;
		}
		K[floor(j/2)] = K[j];
		j = 2*j;
	}
	K[j] = KEY;
}

void HeapSort(int K[], int n){
	int i;
	for(i= floor(n/2); i>=1;i--){
		ADJUST(K,i,n);
	}
	for(i=n-1;i>=1;i--){
		int tmp = K[1];
		K[1] = K[i+1];
		K[i+1] = tmp;
		ADJUST(K,1,i);
	}
}

void printArray(int K[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",K[i]);
	}
}

int main(){
	int K[] = {2, 9, 3, 6, 1, 4, 5, 7, 0, 8};
	int n = sizeof(K)/sizeof(int);
	printf("Mang truoc khi sap xep: ");
	printArray(K,n);
	HeapSort(K,n);
	printf("\nMang sau khi sap xep: ");
	printArray(K,n);
}
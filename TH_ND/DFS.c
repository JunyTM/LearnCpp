#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int n, m, f;
int g[1000][1000];
bool flag[1000];

void input(int g[][1000], int n) {
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y] = g[y][x] = 1;
		flag[i] = false;
	}
}

void display(int g[][1000], int m) {
//	for(int i = 1; i <= m; i++) {
//		if(i == 1) 
//			printf("    %d", i);
//		else 
//			printf(" %d", i);
//	}
//	printf("\n  +------------------------\n");
	for(int i = 1; i <= m; i++) {
//		printf("%d | ", i);
		for(int j = 1; j <= m; j++) {
//			if(g[i][j] > 0) 
				printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

void DFS(int v) {
	printf("%d ", v);
	flag[v] = true;
	for(int i = 1; i <= m; i++) {
		if(g[v][i] && flag[i] == false) {
			DFS(i);
		}
	}
}

int main() {
	scanf("%d%d", &m, &n);
	input(g, n); 
	printf("\nDo thi da khoi tao\n");
	display(g, m);
	printf("\n");
	
	DFS(2);
	
}

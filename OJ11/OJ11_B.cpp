#include<stdio.h>
int tri[40][40];
int main(){
	int n;
	scanf("%d",&n);
	tri[0][0] = 1;
	tri[1][0] = 1;
	tri[1][1] = 1;
	for(int i = 2;i<=n-1;i++){
		tri[i][0] = 1;
		tri[i][i] = 1;
		int k = 1;
		for(int j = 0;j<i-1;j++){
			tri[i][k++] = tri[i-1][j] + tri[i-1][j+1];
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<=i;j++){
			printf("%d ",tri[i][j]);
		}
		printf("\n");
	}
} 

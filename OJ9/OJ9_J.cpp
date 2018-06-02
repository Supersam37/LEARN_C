#include<stdio.h>
#define MAX 101
int pic[MAX][MAX];
int ans[MAX][MAX];
int smooth(int x,int y,int n){
	int num = 0,sum = 0;
	for(int i = x-1;i<=x+1;i++){
		for(int j = y-1;j<=y+1;j++){
			if(i>=0&&i<=n-1&&j>=0&&j<=n-1){
				num++;
				sum+=pic[i][j];
			}
		}
	}
	ans[x][y] = sum/num;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			scanf("%d",&pic[i][j]);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			smooth(i,j,n);
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}

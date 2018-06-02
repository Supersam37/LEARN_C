#include<stdio.h>
#include<string.h>
#define MAX 100001
int X[MAX]; 
int ans[MAX];

int main(){
	int n,k,q;
	scanf("%d %d %d",&n,&k,&q);
	for(int i = 0;i<n;i++){
		scanf("%d",&X[i]);
	}
	k = k%n;//   IMPORTANT!!!
	memcpy(ans+k,X,(n-k)*sizeof(int));//memcpyº¯ÊýÓÃ·¨£¡£¡£¡ 
	memcpy(ans,X+n-k,k*sizeof(int));
	int qst;
//	for(int i = 0;i<n;i++){
//		printf("%d ",ans[i]);
//	}
	for(int j = 0;j<q;j++){
		scanf("%d",&qst);
		printf("%d\n",ans[qst]);
	}
}

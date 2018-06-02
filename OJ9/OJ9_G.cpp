#include<stdio.h>
#define MAX 55//ÄæÓ³ÉäË¼Ïë 
int seq[MAX];
int main(){
	int n,d;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&d);
		seq[d] = i+1;
	}
	for(int i = 0;i<n;i++){
		printf("%d\n",seq[seq[i+1]]);
	}
} 

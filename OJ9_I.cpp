#include<stdio.h>
int seq[1010] = {0};
int gen(int n,int p,int k){
	int sum = 0,avg,*pt;
	for(int i = 1;i<=k-n;i++){
		pt = &seq[n+i-1];
		sum = 0; 
		for(int j = 0;j<p;j++){
			sum+=*(pt-j);
		}
		avg = sum/p;
		seq[i+n] = avg;
	}
}
int main(){
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	for(int i = 1;i<=n;i++){
		scanf("%d",&seq[i]);
	}
	gen(n,p,k);
	printf("%d",seq[k]);
} 

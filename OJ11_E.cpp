#include<stdio.h>
int high[1005];
int low[1005];
long long sum[1005];
int count(int x,int n);
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0;i<n;i++){
		scanf("%d %d",&low[i],&high[i]);
	}
	for(int i = 0;i<n;i++){
		sum[i] = count(high[i],n)*((long long)high[i]);// extremely important!!!!!
	}
	long long max = 0;
	for(int i = 0;i<n;i++){
		if(sum[i]>max){
			max = sum[i];
		}
	}
	printf("%lld",max);
}

int count(int x,int n){
	int num = 0;
	for(int i = 0;i<n;i++){
		if(x>=low[i]&&x<=high[i]){
			num++;
		}
	}
	return num;
}

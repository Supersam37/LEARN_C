#include<stdio.h>
#include<stdlib.h>
int array[15];
int candy[20];
int print(int a,int b,int n,int pos){
	for(int i = a;i<=b-n+1;i++){
		array[pos]=i+1;
		if(n==1){
			int sum = 0;
			for(int j = 0;j<=pos;j++){
				printf("%d",array[j]);
				sum+=candy[array[j]-1];	
			}
			printf(" %d\n",sum);
		}
		else{
			print(i+1,b,n-1,pos+1);
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	for(int i = 0;i<m;i++){
		scanf("%d",&candy[i]);
	} 
	print(0,m-1,n,0);
} 

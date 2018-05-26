#include<stdio.h>

int main(){
	int num[5];
	for(int i = 0;i<5;i++){
		scanf("%d",&num[i]);
	}
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			if(num[j]<num[j+1]){
				int temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	
	long long max = 0,min = 0;
	for(int i = 0;i<4;i++){
		max+=num[i];
	}
	for(int i = 1;i<5;i++){
		min+=num[i];
	}
	printf("%ld %ld",min,max);
} 

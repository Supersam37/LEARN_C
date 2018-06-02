#include<stdio.h>
#define MAX 1001
int stick[MAX] = {0};
int status[MAX] = {0};
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&stick[i]);
	}
	int num = n,flag = 1;
	while(1){
		if(flag == 1&&num!=0) printf("%d\n",num);
		flag = 0;
		for(int i = 0;i<n;i++){
			int b = stick[i];
			if(status[i] == 0) stick[i]--;
			if(stick[i] == 0&&b!=0) {
				status[i] = 1;
				flag = 1;
				num--;
			}
		}
		if(num==0) break;
	}
	
} 

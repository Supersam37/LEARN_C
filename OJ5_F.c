#include<stdio.h>
#define MAX 100001
int interval[MAX] = {0};
void print();
int main(){
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		if(interval[a]==0){
			interval[a] = b;
			continue;
		}
		if(interval[a]>b) interval[a] = -a;
		else if (interval[a]<b) interval[a] = -b;
	}
	print();
} 

void print(){
	int i,j;
	for(i = 0;i<=100000;i++){
		if(interval[i]<=0) continue;
		int max = 0;
		for(j = i+1;j<=interval[i];j++){
			if(interval[j]<0) interval[j] = -interval[j];
			if (interval[j]>max) max = interval[j];
		}
		if(max==0) printf("%d %d\n",i,interval[i]);
		i = (max>interval[i])? (max) : (interval[i]);
	}
}

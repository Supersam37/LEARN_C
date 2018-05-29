//区间合并 
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAX_N (1024*1024)
int range[MAX_N];

void print_zone(){
	int i,n;
	for(i = 0;i<MAX_N;i++){
		if(range[i]==0)
			continue;
		printf("%d ",i);
		for(n = range[i];i<=n;i++)
			if(range[i]>n)
				n = range[i];
		i--;
		printf("%d\n",i); 
		
	}
}

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b) == 2){
		if(b > range[a])
			range[a] = b;
	}
	print_zone();
	return 0;
} 

 

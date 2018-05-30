#include<stdio.h>
#include<string.h>
#define MAXL 205 
#define MAXN 1005 

char s[MAXN][MAXL];

int main(){
	int t = 0,num,max=0;
	char (*lg)[MAXL];
	while(scanf("%s",s[t++])!=EOF){ //gets(s[t++])究竟能不能用？？ 
		num = strlen(s[t-1]);
		if(num>max) {
			max = num;
			lg = &s[t-1];
		}
	}
	printf("%d:%s",max,*lg);
	return 0;
}

#include<stdio.h>
#define MAX 100
int main(){
	char str1[MAX],str2[BUFSIZ];
	gets(str1);
	puts(str1);
	printf("printf:%s",str1);
	printf("\n");
	
	fgets(str2,BUFSIZ,stdin);
	fputs(str2,stdout);
	
	printf("DONE");
	return 0;
} 

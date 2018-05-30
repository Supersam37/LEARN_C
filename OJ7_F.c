#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXL 205
#define MAXN 1001
int sort1(int);
int sort2(int);
char str[MAXN][MAXL];
char *str1[MAXN];
int main(){
	int n=0;
	while(scanf("%s",&str[n])!=EOF){//gets()¾Í²»ÐÐ£¿£¿£¿ 
		str1[n] = str[n];
		n++;
	}
	sort1(n);
	sort2(n);
	for(int i=0;i<n;i++){
		puts(str1[i]);
	}
	return 0;
}

int sort1(int n){
	char *temp = str[1001];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(strlen(str1[j])<strlen(str1[j+1])){
				temp = str1[j+1];
				str1[j+1] = str1[j];
				str1[j] = temp;
			}
				}
			}	
}
int sort2(int n){
	char *temp = str[1001];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(strlen(str1[j])==strlen(str1[j+1])){
				if(str1[j][0]>str1[j+1][0]){
				temp = str1[j+1];
				str1[j+1] = str1[j];
				str1[j] = temp;
				
				
				}
			}
			
		}
	}
}

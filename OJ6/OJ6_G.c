#include<stdio.h>
#include<string.h>
#define  MAX 201

char A[MAX],B[MAX];
int ans[405]={0};
int allzero(int i);
int main(){
	scanf("%s",A);
	scanf("%s",B); 
	int lenA = strlen(A),lenB = strlen(B);
	for(int i = lenB-1;i>=0;i--){
		int index = lenB-1-i;
		for(int j = lenA-1;j>=0;j--){
			ans[index] = ans[index] + (A[j]-'0')*(B[i]-'0');
			index++;
		}
	}
	for(int i = 0;ans[i]!=0;i++){
		ans[i+1] = ans[i+1]+(ans[i]/10);
		ans[i] = ans[i]%10;
	}
	int i;
	for(i = 0;!allzero(i);i++)
		;
	if(i==0) printf("0");
	else
		for(int j = i-1;j>=0;j--)
			printf("%d",ans[j]);
}

int allzero(int i){
	for(int j = i;j<=405;j++){
		if(ans[j]!=0) return 0;
	}
	return 1;
}

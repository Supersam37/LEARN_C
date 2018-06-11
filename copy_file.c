#include<stdio.h>

int main(){
	FILE* fp1,*fp2;
	if((fp1 = fopen("newfile.txt","r"))==NULL){
		perror("Can\'t open file newfile.txt\n");
		return 1;
	}
	if((fp2 = fopen("copyfile.txt","w"))==NULL){
		perror("Can\'t open file copyfile.txt\n");
		return 1;
	}
	char c,s[100];
	while(!feof(fp1)){
		fgets(s,100,fp1);
		fputs(s,fp2);
		puts(s);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
} 

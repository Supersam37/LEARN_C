#include<stdio.h>

int main(){
	FILE* fp;
	if((fp = fopen("newfile.txt","w"))==NULL){
		perror("Can\'t open file\n");
		return 1;
	}
	char c,s[100];
	while((c = getchar())!='#'){
		putchar(c);
		fputc(c,fp);	
	}
	fclose(fp); 
	return 0;
} 



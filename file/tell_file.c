#include<stdio.h>

int main(){
	FILE* fp;
	if((fp = fopen("newfile.txt","r"))==NULL){
		perror("Can\'t open file\n");
		return 1;
	}
	long ind;
	fseek(fp,100,SEEK_SET);
	char buf[BUFSIZ];
	fgets(buf,BUFSIZ,fp);
	fputs(buf,stdout);
} 



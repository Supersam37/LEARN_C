#include<stdio.h>
#include<string.h>

char arr[] = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main(){
	char c;
	while((c = getchar())!=EOF){
		if(strchr(arr,c)!=NULL)
			putchar(*(strchr(arr,c)-1));
		
		else 
			putchar(c);
	}
}

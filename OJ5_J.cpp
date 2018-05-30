#include<stdio.h>

char map [][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
char ans[20];
void draw(char *s,int pos){
	if(s[pos] =='\0'){
		ans[pos] = '\0';
		puts(ans); 
		return;
	}
	int c = s[pos]-'0';
	int n = (c==7||c==9) ? 4:3;
	for(int i = 0;i<n;i++){
		ans[pos] = map[c][i];
		draw(s,pos+1);
	}
}

int main(){
	char str[20];
	gets(str);
	draw(str,0);
	return 0;
}

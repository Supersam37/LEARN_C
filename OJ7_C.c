#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 40000

int sort(int);
char *find(char *, char *);
char str1[MAX];
char str2[MAX];
char str[105][40];
char *find(char *str, char *key){
	char *ind = strstr(str,key);
	if(ind==NULL) return NULL;
	else if(!isalpha(*(ind-1))&&!isalpha(*(ind+strlen(key)))) return ind;
	else return find(ind+1,key);
}
int main(){
	char *index[2000];
	gets(str1);
	gets(str2);
	int t = 0;
	for(int i = 0;i<MAX;i++){
		if((str1[i]==','||str1[i] == '{')||str1[i]==' '){
			index[t++] = &str1[i];
			str1[i] = '\0';
		}
		if(str1[i]=='}'){
			str1[i] = '\0';
			break;
			
		}	
	}
	int t1 = 0;
	for(int j = 0;j<t;j++){
		if(index[j]==NULL) break;
		if (j!=t-1  && (index[j+1]-index[j]==1) ) continue;
		if(find(str2,index[j]+1)!=NULL && *(index[j]+1)!='\0'){
			sscanf(index[j]+1,"%s",str[t1++]);
		}
	}
	if(t1==0) {
		printf("NONE");
		return 0;
	}
	sort(t1);
	for(int i = 0;i<t1;i++){
		if(!strcmp(str[i],str[i+1])) continue;
		printf("%s ",str[i]);
	}
	return 0;
}

int sort(int t){
	char temp[40];
	for(int i = 0;i<t-1;i++){
		for(int j = 0;j<t-1;j++){
			if(strcmp(str[j],str[j+1])>0){
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
			
		}
	}
	return 0;
}

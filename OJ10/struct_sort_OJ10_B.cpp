#include<stdio.h>
#include<stdlib.h>
#define MAX_N 200005
#define MAX_L 20
//�Խṹ��������򣬲���ԭ˳����� 
struct sentry{
	double talld;
	char talls[MAX_L];
	int num0;
	int numh;
}list[MAX_N];
int cmp1(const void *a1,const void *b1);
int cmp2(const void *a,const void *b);

int main(){
	int n = 0;
	while(scanf("%s",list[n].talls)!=EOF){
		list[n].num0 = n+1;
		list[n].talld = atof(list[n].talls);
		n++;
	}
	qsort(list,n,sizeof(list[0]),cmp1);  //qsortӦ�� !!!
	list[0].numh = 1;
	for(int j = 1,i = 1;j<n;j++){
		if(list[j].talld<list[j-1].talld)//��� 
		list[j].numh = ++i;
		else
		list[j].numh = i;
	}
	qsort(list,n,sizeof(list[0]),cmp2);  //qsortӦ�� !!!
	for(int j = 0;j<n;j++){
		printf("%d:%s ",list[j].numh,list[j].talls);
	}
	
}
//���ź��� 
int cmp1(const void *a1,const void *b1){
	struct sentry *a = (struct sentry*)a1;//ǿ������ת�� 
	struct sentry *b = (struct sentry*)b1;
	return (a->talld<b->talld)?1:-1;
}

int cmp2(const void *a,const void *b){
	return ((*(struct sentry*)a).num0>(*(struct sentry*)b).num0)?1:-1;
}

//cmp����д���� 
//int cmp1(const struct sentry *a,const struct sentry *b){
//	return (a->talld<b->talld)?1:-1;
//}
//
//int cmp2(const void *a,const void *b){
//	return ((*(struct sentry*)a).num0>(*(struct sentry*)b).num0)?1:-1;
//}

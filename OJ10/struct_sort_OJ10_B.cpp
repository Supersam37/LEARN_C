#include<stdio.h>
#include<stdlib.h>
#define MAX_N 200005
#define MAX_L 20
//对结构体进行排序，并按原顺序输出 
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
	qsort(list,n,sizeof(list[0]),cmp1);  //qsort应用 !!!
	list[0].numh = 1;
	for(int j = 1,i = 1;j<n;j++){
		if(list[j].talld<list[j-1].talld)//标号 
		list[j].numh = ++i;
		else
		list[j].numh = i;
	}
	qsort(list,n,sizeof(list[0]),cmp2);  //qsort应用 !!!
	for(int j = 0;j<n;j++){
		printf("%d:%s ",list[j].numh,list[j].talls);
	}
	
}
//快排函数 
int cmp1(const void *a1,const void *b1){
	struct sentry *a = (struct sentry*)a1;//强制类型转换 
	struct sentry *b = (struct sentry*)b1;
	return (a->talld<b->talld)?1:-1;
}

int cmp2(const void *a,const void *b){
	return ((*(struct sentry*)a).num0>(*(struct sentry*)b).num0)?1:-1;
}

//cmp错误写法？ 
//int cmp1(const struct sentry *a,const struct sentry *b){
//	return (a->talld<b->talld)?1:-1;
//}
//
//int cmp2(const void *a,const void *b){
//	return ((*(struct sentry*)a).num0>(*(struct sentry*)b).num0)?1:-1;
//}

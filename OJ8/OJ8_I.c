#include<stdio.h>
#include<stdlib.h>
#define MAX 1001
struct stu{
	int no;
	int score;
	int pun;
	int rank;
}student[MAX]; 
int comp(const void*,const void*);
int main(){
	int m;
	scanf("%d",&m);
	for(int i = 0;i<m;i++){
		int n;
		scanf("%d",&n);
		for(int j = 0;j<n;j++){
			student[j].no = j+1;
			scanf("%d %d",&student[j].score,&student[j].pun);
		}
		qsort(student,n,sizeof(struct stu),comp);
		int qst;
		scanf("%d",&qst);
		for(int j = 0;j<qst;j++){
			int arank;
			scanf("%d",&arank);
			printf("%d\n",student[arank-1].no);
		}	
	}

} 
int comp(const void *s1,const void *s2){
	struct stu* s11 = (struct stu*) s1;//复杂！！oj上可以直接在参数表改 
	struct stu* s21 = (struct stu*) s2;
	if(((*s21).score)==((*s11).score)&&((*s21).pun)==((*s11).pun)) return ((*s11).no)-((*s21).no);
	else if((s21->score)==(s11->score)&&((*s21).pun)!=((*s11).pun)) return (s11->pun)-(s21->pun);
	else if((s21->score)!=(s11->score)) return (s21->score)-(s11->score);
}

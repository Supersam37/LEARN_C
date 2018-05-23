#include<stdio.h>

struct student
{
	int num;
	char name[20];
};

struct student stu[3] = {
{10101,"lilin"},
{10102,"Echo"},
{10103,"Wiliam"}};

main(){
	int i = 0;
	struct student *p;
	printf("NO\tNAME\n");
	for(p=stu;p<stu+3;p++)
	printf("%d\t%s\n",p->num,p->name);
}

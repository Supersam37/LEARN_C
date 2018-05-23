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
	for(int i = 0;i<3;i++)
	printf("%d\t%s\n",stu[i].num,stu[i].name);
}

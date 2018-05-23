#include<stdio.h>

struct student
{
	int num;
	char name[20];//定义结构数组 
};

struct student stu[3] = {//声明结构数组 
{10101,"lilin"},
{10102,"Echo"},
{10103,"Wiliam"}};

main(){
	int i = 0;
	struct student *p;
	printf("NO\tNAME\n");
	for(p=stu;p<stu+3;p++)//使用指针在结构数组中进行循环 
	printf("%d\t%s\n",p->num,p->name);
}

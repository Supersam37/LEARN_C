#include<stdio.h>

struct student
{
	int num;
	char name[20];//����ṹ���� 
};

struct student stu[3] = {//�����ṹ���� 
{10101,"lilin"},
{10102,"Echo"},
{10103,"Wiliam"}};

main(){
	int i = 0;
	struct student *p;
	printf("NO\tNAME\n");
	for(p=stu;p<stu+3;p++)//ʹ��ָ���ڽṹ�����н���ѭ�� 
	printf("%d\t%s\n",p->num,p->name);
	
	//�ڽṹ�����в���
	int number;
	scanf("%d",&number);
	struct student *result,*find(int);
	result = find(number);
	if(result!=NULL)
		printf("%d\t%s",result->num,result->name);
	else
		printf("Not found!");
}

struct student *find(int number){//�ڽṹ�����в��Һ��� 
	int i;
	for( i = 0;i<3;i++){
		if(stu[i].num==number){
			return &stu[i];
		}
	}
	return NULL;
}

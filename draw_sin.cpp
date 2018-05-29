#include<stdio.h>
#include<string.h> 
#include<math.h>
#define MAX_H 100
#define MAX_W 400

char pic[MAX_H][MAX_W];
int init(int,int);
int makepic(int,int,int);
int print(int,int);

int main(){
	int w,h,ang;
	scanf("%d%d%d",&w,&h,&ang);
	init(w,h);
	makepic(w,h,ang);
	print(w,h);
	return 0;
} 

int init(int w,int h){
	for(int j = 1;j<=w;j++) pic[0][j] = ' ';
	pic[0][0] = '|';
	//pic[0][w] = 'D';
	for(int i = 1;i<h;i++) strcpy(pic[i],pic[0]);
	for(int j = 1;j<=w;j++) pic[h/2][j] = '-';
	if((h%2)==0) 
		strcpy(pic[h],pic[0]);

	
}
int makepic(int w,int h,int ang){
	double x,c = 3.1415926/180;
	double y1,y2,h1 = h/2; 
	for(int i = 1;i<=w;i++){
		x = (double)(i*ang*c)/w;
		y1 = h1+sin(x)*h1;
		y2 = h1+cos(x)*h1;
		int y3 = (int)y1;
		int y4 = (int)y2;
		pic[y3][i] = '*';
		//printf("%d:%f  %d\n",i,y1,y3);
		pic[y4][i] = '^';
	}
	return 0;
}

int print(int w,int h){
	for(int i = 0;i<=h;i++){
		for(int j = 0;j<=w;j++)
			printf("%c",pic[i][j]);
		printf("\n");
	}
}

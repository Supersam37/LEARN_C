#include<stdio.h>
int card[105];
int fmax(int a,int b);
int move(int a,int b,int avg);
int sum(int a,int b);
int main(){
	int n;
	scanf("%d",&n);
	int sum = 0,avg;
	for(int i = 0;i<n;i++){
		scanf("%d",&card[i]);
		sum+=card[i];
	}
	avg = sum/n;
	int step = 0;
	step = move(0,n-1,avg);
	printf("%d",step);
} 

int fmax(int a,int b){
	int max = 0,index;
	for(int i = a;i<=b;i++){
		if(card[i]>max) {
			max = card[i];
			index  = i; 
		}
	} 
	return index;
}

int sum(int a,int b){
	int total = 0;
	for(int i = a;i<=b;i++)
		total+=card[i];
	return total;
}
int move(int a,int b,int avg){
	if(a==b) return 0;
	if(a==b-1){
		if (card[a]==card[b]) return 0;
		return 1;
	}
	int left = 1,right = 1,maxi = fmax(a,b);
	if(maxi>=a+1) {
		int numl = (maxi-a)*avg-sum(a,maxi-1);
		card[maxi-1] = card[maxi-1]+numl;
		if(numl==0) left = 0;
	}
	if(maxi<=b-1) {
		int numr = (b-maxi)*avg-sum(maxi+1,b);
		card[maxi+1] = card[maxi+1]+numr;
		if(numr==0) right = 0;
	}
	if(maxi == a) return right+move(maxi+1,b,avg);
	if(maxi == b) return left+move(a,maxi-1,avg);
	return left+right+move(maxi+1,b,avg)+move(a,maxi-1,avg);
}

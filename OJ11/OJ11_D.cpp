#include<stdio.h>
int me[105];
int other[105];
int sort1(int n);
int sort2(int n);
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",&me[i]);
	}
	for(int i = 0;i<n;i++){
		scanf("%d",&other[i]);
	}
	sort1(n);
	sort2(n);
	int num = 0,index = 0;
	for(int i = 0;i<n;i++){
		for(int j = index;j<n;j++){
			if(me[j]>other[i]){
				num++;
				index = j+1;
				break;
			}
		}
	}
	printf("%d",num);
} 

int sort1(int n){
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-1;j++){
			if(me[j]>me[j+1]){
				int temp = me[j];
				me[j] = me[j+1];
				me[j+1] = temp;
			}
		}
	}
}
int sort2(int n){
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-1;j++){
			if(other[j]>other[j+1]){
				int temp = other[j];
				other[j] = other[j+1];
				other[j+1] = temp;
			}
		}
	}
}

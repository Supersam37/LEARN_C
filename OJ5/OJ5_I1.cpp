#include<stdio.h> 
#include<math.h> 
#define MAX 101

int lst[MAX];
int srch(int,int,int);
int sort(int);
int re[MAX] = {0};

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&lst[i]);
	}
	sort(n);
	int num = 0,all;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			all = lst[i]+lst[j];
			if (srch(all,j+1,n-1)&&re[all]==0){
					num++;
					re[all] = 1;
				}
			} 
		}
	
	printf("%d",num);
}

int srch(int x,int low,int high){
//	int mid = (high+low)/2;
//	if(high<low) return 0;
//	if(x==lst[mid]) return 1;
//	else{
//		if(x>lst[mid]) return srch(x,mid+1,high);
//		if(x<lst[mid]) return srch(x,low,mid-1);
//	}
	for(int i = low;i<=high;i++){
		if (x==lst[i]) return 1;
	}
	return 0;
}

int sort(int n){
	for(int i=0;i<n-1;i++){
		for (int j=0;j<n-1;j++){
			if(fabs(lst[j])>fabs(lst[j+1])){
				int temp = lst[j];
				lst[j] = lst[j+1];
				lst[j+1] = temp;
			}
		}
	}
}


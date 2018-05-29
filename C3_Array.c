#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0])) //ArrayNum
int bubble_sort(int *a,int n);//冒泡排序，从小到大 
int *bin_find(int *a,int key,int low,int high);//二分查找，从小到大 
int main(){
	int a[10] = {0,1,2,3,4,5,6,7,8,9},b[11],i;
	memcpy(b,a,sizeof(a));  //数组复制，前为dest； 
	for(i = 0;i<ArrayNum(a);i++)
		printf("%d:%d ",i,b[i]);
		printf("\n");
		
	int s[] = {234,4254,245,25,1,45,564,5678,235,36,7654,3452,1245,5637,653452,12436,67123,87465,12345126};
	
	bubble_sort(s,ArrayNum(s));
	for(int i = 0;i<ArrayNum(s);i++)
		printf("%d ",s[i]);
	printf("\n");
	
	int *index,key[] = {653452,1245,24351214};
	index = bin_find(s,key[0],0,ArrayNum(s)-1);
	printf("%d\n",index==NULL ?-1:index-s);
	index = bin_find(s,key[1],0,ArrayNum(s)-1);
	printf("%d\n",index==NULL ?-1:index-s);
	index = bin_find(s,key[2],0,ArrayNum(s)-1);
	printf("%d\n",index==NULL ?-1:index-s);
	
} 
//冒泡排序 
int bubble_sort(int *a,int n){
	for(int i = 0;i<n-1;i++){
		for(int j = 0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
} 
//二分查找
int *bin_find(int *a,int key,int low,int high){
	if(low>high) return NULL;
	int mid = (low+high)/2;
	if(key==a[mid]) return &a[mid];
	else if(key<a[mid]) return bin_find(a,key,low,mid-1);
	else if(key>a[mid]) return bin_find(a,key,mid+1,high);
}
 

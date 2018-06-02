#include<stdio.h>
long long f(int);
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",f(n));
	} 

} 
long long f(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	if(n == 3) return 2;
	else return (n-1)*(f(n-1)+f(n-2));
}

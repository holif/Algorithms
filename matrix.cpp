#include<stdio.h>  
#define MAX 100
void func(int n,int a[][MAX]){
	int s=1,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			a[i-j][j] = s++;
		}
	}
}
void print(int a[][MAX],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int a[MAX][MAX];
	func(10,a);
	print(a,10);
	return 0;
}

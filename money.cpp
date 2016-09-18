#include<stdio.h>
int a[7] = {2,5,10,20,50,100};
int count = 0;
int func(int n){
	int i, tmpn=n, tmpi = 5;
	if(n>=2){
		for(i = 5; i >= 0; i--){
			if(n==0){
				return count;
			}
			if(n>=a[i]){
				if(i-1>=0){
					if((n%a[i])%a[i-1]==1){
						--i;
					}
				}
				tmpn = n;
				tmpi = i;
				n = n % a[i];				
				count+= tmpn/a[i];
			} 
			if(i==0 && n>1){
				if(tmpi==0){
					++tmpi;
				}
				i=tmpi;
				n=tmpn;
				--count;
			}
			if(i==0&&n==1){
				return -1;
			}
		}
		return count;
	} else {
		return -1;
	}
}
int main(){
	printf("%d\n",func(7));
	return 0;
}

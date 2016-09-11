/*** 二分查找 **/
#include<stdio.h>
#include<stdlib.h>

int  comp(const void *a,const void *b){
	return *(int*)a - *(int*)b;
}

int binarySearch(int key, int a[],int len ){
	
	int l = 0, h = len-1 , mid ;
	
	qsort(a,len,sizeof(int),comp); 
	
	while(l<=h){
		mid = l +(h-l)/2;
		
		if(key>a[mid]){
			l=mid+1;
		} else if (key<a[mid]){
			h = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main(){
	int a[] = {12,23,2,56,41,52,83,62,12,45,65,89,23,22};
	
	printf("%d\n",binarySearch(89,a,14));
	
	return 0;
}

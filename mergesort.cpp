#include<stdio.h>
#define SIZE 10

void merge(int a[], int low, int mid, int hig){
	int tmp[SIZE];
	
	int i=low, j=mid+1, k=0;
	
	while(i<=mid&&j<=hig){
        if(a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
	}
	
	while(i<=mid) tmp[k++] = a[i++];
    while(j<=hig) tmp[k++] = a[j++];
    
    for(i=0; i<k; i++) {
        a[low+i] = tmp[i];
    }
}

void sort(int arr[], int low, int hig){
	
	if(low==hig) return;
	
	int cen = (low+hig)/2;
	
	sort(arr,low,cen);
	sort(arr,cen+1,hig);
	merge(arr,low,cen,hig);
}


int main(){
	int a[] = {15,3,5,8,4,3,6,9,11,91};
	sort(a,0,9);
	for(int i = 0; i<SIZE;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}

/**  输出NUM和NUM的倍数，还有包含NUM的数字  */
#include<stdio.h>
#define NUM 7
int is_ex(int n) {
	int tmp = 0;
	if(n%NUM==0) {
		return 1;
	} else {
		while(n>0) {
			tmp = n%10;
			if(tmp==NUM) {
				return 1;
			}
			n = n/10;
		}
		return 0;
	}
}
int func(int n) {
	for(int i = 1; i<=n; i++) {
		if(is_ex(i)){
			printf("%d\n",i);
		}
	}
}
int main() {
	func(20);
	return 0;
}

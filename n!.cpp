/**  n!���һλ��0����  */
#include<stdio.h> 
//��ȡ����n�����һλ������
int getnum(int n){
	while(n>0){
		if(n%10!=0){
			return n%10;
		} else {
			n = n/10;
		}
	}
	return 0;
}
int func(int n){
	int num;
	if(n==1||n==2){
		return n;
	}else {
		num = n*(func(n-1)%10);
		return getnum(num);
	}
}
int main(){
	printf("%d\n",func(1101));
	return 0;
}
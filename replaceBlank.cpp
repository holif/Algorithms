#include<stdio.h>
void replaceSpace(char str[], int len){
	if(str == NULL|| len <= 0){
		return;
	}
    int sumspace = 0,oldchar = 0,newchar = 0;//sumspace空格总数 oldchar原串长度  newchar新串长度 
    
    while (str[oldchar]!='\0'){
        if(' '==str[oldchar]){
        	sumspace++;
		}
		oldchar++;
    }
    
    newchar = oldchar+sumspace*2 ;
    
	if(len<newchar){
		return;
	}

    while(oldchar>=0){
    	if(str[oldchar]==' '){
    		str[newchar--] = '0';
    		str[newchar--] = '2';
    		str[newchar--] = '%';
		}else{
			str[newchar--] = str[oldchar];
		}
		--oldchar;
	}
	printf("%s",str);
}
int main(){
	char pchar[20] = "hello world test";
	replaceSpace(pchar,20);
	return 0;
}
#include <stdio.h>
struct X{
    static int i;
    X(){
        ++i;
        printf("%d\n",i);
    }
};

int X::i = 0;
int main(){
    X arr[100];
    return 0;
}
/*
方法二：
#include <stdio.h>
#include <stdlib.h>
int main(void) { 
	return system("seq 1 100");
}
*/

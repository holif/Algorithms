/***皇后问题***/
#include <stdio.h>
#include <math.h>
#define N 15    //规定皇后最多为15个 
int q[N];         //记录各皇后所在的列号
int count = 0;
int check(int i,int k) { //检验第i行的k列上是否可以摆放皇后
    int j=1;
    while(j<i) { //j=1~i-1是已经放置了皇后的行
        //第j行的皇后是否在k列或(j,q[j])与(i,k)是否在斜线上
        if(q[j]==k || abs(j-i)==abs(q[j]-k))
            return 0;
        j++;
    }
    return 1;
}
void print(int n) {
    int i,j;
    printf("第%d个解：",count);
    for(i=1; i<=n; i++)
        printf("(%d,%d) ",i,q[i]);
    printf("\n");
}
void place(int i,int n) {//放置皇后到棋盘上
    int j;
    if(i>n) {
        ++count;
        print(n);
    } else {
        for(j=1; j<=n; j++) { //试探第i行的每一个列

            if(check(i,j)) {
                q[i] = j;
                place(i+1,n);  //上一任务完成时才进行下一个任务
            }
        }
    }
}
int main(void) {
    int n;
    scanf("%d",&n);
    if(n<=15)
        place(1,n);
    printf("%d\n",count);
    return 0;
}
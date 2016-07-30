/***快速排序***/
#include <stdio.h>
int a[20]= {6,1,2,7,9,3,4,5,10,8,0}, n;
void quicksort(int left,int right) {
    int i,j,t,temp;
    if(left>right)
        return;

    temp=a[left]; //temp来存储基准数
    i=left;
    j=right;
    while(i != j) {
        //先从右边向左找
        while(a[j]>=temp && i<j)
            j--;
        //再从左边向右找
        while(a[i]<=temp && i<j)
            i++;
        //交换两个数在数组中的位置
        if(i<j) {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //将基准数归位
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);//继续处理左边的数列
    quicksort(i+1,right);//继续处理右边的数列
}
int main() {
    int i,j,t;
    n = 10;
    quicksort(0,n);

    //输出排序结果
    for(i=0; i<=n; i++)
        printf("%d ",a[i]);
    return 0;
}
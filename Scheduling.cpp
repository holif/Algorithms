/***最佳调度***/
#include<stdio.h>
int n=7,k=3,best=66666;
int len[99];
int t[99]= {2,14,4,16,6,5,3};
int comp() {
    int tmp=0;
    for(int i=0; i<k; i++)
        if(len[i]>tmp)
            tmp=len[i];
    return tmp;
}
void search(int dep,int *len,int *t) {
    if(dep==n) {
        int tmp=comp();
        if(tmp<best)
            best=tmp;
        return;
    }
    for(int i=0; i<k; i++) {
        len[i]+=t[dep];
        if(len[i]<best)
            search(dep+1,len,t);
        len[i]-=t[dep];
    }
}
int main() {
    int i;
    for (i=0; i<k; i++)
        len[i]=0;
    search(0,len,t);
    printf("%d\n",best);
    return 0;
}
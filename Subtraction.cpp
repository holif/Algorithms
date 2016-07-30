/***大数相减***/
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main() {
    char s1[500],s2[500],t[500];
    int flg=1,i,j,k=0,*a,n;
    scanf("%s%s",s1,s2);
    i=strlen(s1)-1;
    j=strlen(s2)-1;
    n=i>j? i:j;
    a=(int*)malloc(n*sizeof(int));
    if(i==j) {
        flg=strcmp(s1,s2);
        if(flg==0)
            printf("0");
    } else {
        if(i<j) {
            flg=-1;
            strcpy(t,s1);
            memset(s1,0,sizeof(s1));
            strcpy(s1,s2);
            memset(s2,0,sizeof(s2));
            strcpy(s2,t);
            k=i;
            i=j;
            j=k;
            k=0;
        }
        while(i>=0||j>=0) {
            if(i>=0&&j>=0) {
                a[k]=s1[i]-s2[j];
                if(a[k]<0) {
                    a[k]=10+a[k];
                    s1[i-1]=s1[i-1]-1;
                }
                j--;
            } else if(j<0)
                a[k]=s1[i]-'0';
            k++;
            i--;
        }
        k=k-1;
        i=k;
        while(i>0)
            if(a[i]>0) {
                k=i;
                i--;
                break;
            }
        if(flg<0)
            printf("-");
        while(k>=0) {
            printf("%d",a[k]);
            k--;
        }
    }
    free(a);
    return 0;
}
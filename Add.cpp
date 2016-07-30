/***大数相加***/
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int main()
{
	char s1[500],s2[500];
	int i,j,k=0,*a,n;
	scanf("%s%s",s1,s2);
	i=strlen(s1)-1;
	j=strlen(s2)-1;
	n=i>j? i:j;
	a=(int*)malloc((n+2)*sizeof(int));
	while(k<=n+1)
	     a[k++]=0;
	k=0;
	while(i>=0||j>=0)
	{
	     if(i>=0&&j>=0)
		  a[k]+=(s1[i]-'0')+(s2[j]-'0');
	     else if(j<0)
		  a[k]+=s1[i]-'0';
	     else
		  a[k]+=s2[j]-'0';
	     if(a[k]>=10)
	     {
		  a[k]=a[k]-10;
		  a[k+1]=1;
	     }
	     k++;i--;j--;
	}
	if(a[k]==0)
	     k=k-1;
	while(k>=0)
	     printf("%d",a[k--]);	
  	free(a);	
	return 0;
}
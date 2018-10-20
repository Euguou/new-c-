#include<iostream>
#include<cstdio>
using namespace std;
int n,a[210],d[210][210],s;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[n+i]=a[i];
    }
    for (int len=2;len<=n;len++)
    {
    	for (int i=1;i<=2*n-len+1;i++)
   		{
        	int j=len+i-1;
        	for (int k=i;k<j;k++)
            d[i][j]=max(d[i][j],d[i][k]+d[k+1][j]+a[i]*a[k+1]*a[j+1]);
   		 }
    }
    for(int i=1;i<=n;i++)
        s=max(s,d[i][i+n-1]);
    printf("%d",s);
    return 0;

}

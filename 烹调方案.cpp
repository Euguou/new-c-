#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <map>
#define maxn 1000001
#include <vector>
using namespace std;
int read()
{
    char c=getchar();
    int x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
       x=(x<<3)+(x<<1)+c-48,c=getchar();
    return x;
}
void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
struct Edge{
	int a,b,c;
}P[maxn];
bool bj(Edge x, Edge y)
{
	return x.c * y.b < y.c * x.b;
}
int f[maxn];
int main()
{
	int T,N;
	T=read();
	N=read();
	for(int i=1;i<=N;i++)
	{
		P[i].a=read();
	}
	for(int i=1;i<=N;i++)
	{
		P[i].b=read(); 
	}
	for(int i=1;i<=N;i++)
	{
		P[i].c=read();
	}
	sort(P+1,P+1+N,bj);
	for(int i=1;i<N;i++)
	{
		for(int j=T;j-P[i].c>=0;j--)
		{
			f[j]=max(f[j],f[j-P[i].c]+P[i].a-j*P[i].b);
		}
	}
	int ans=0;
	for(int i=1;i<=T;i++)
	{
		ans=max(f[i], ans);
	}
	write(ans);
	return 0;
}
/*
 ÊäÈë
74 1
502
2
47

Êä³ö
408 
*/

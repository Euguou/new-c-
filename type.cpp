#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define fo(a,b,c) for(int a=b;a<=c;a++)
using  namespace std;
int read()
{
    int a=0,f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
    return f?-a:a;
}

void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

const int N=100001;
int bel[N],son[N],bro[N],ne[N],head[N],ask[N];
char c[N],ans[N],arr[N];

void dfs(int u,int len){
    arr[len]=c[u];
    for(int x=head[u];x;x=ne[x])
	{
		ans[x]=arr[ask[x]];
	}
    for(int x=son[u];x;x=bro[x])
	{
		dfs(x,len+1);
	}
}

int main()
{
	int N;
	int nt=0,nu=0,nq=0;
	N=read();
	fo(i,1,N){
        scanf("\n");
        char opt=getchar();
		getchar();
        if(opt=='T')
		{
            bel[++nu]=++nt;
            bro[nt]=son[bel[nu-1]];
            son[bel[nu-1]]=nt;
            c[nt]=getchar(); 
        }
        if(opt=='U')
		{
			bel[++nu]=bel[nu-read()-1];
		}
        if(opt=='Q')
		{
            ne[++nq]=head[bel[nu]];
            head[bel[nu]]=nq;
            ask[nq]=read();
        }
    }
    dfs(0,0);
    fo(i,1,nq)
	{
		printf("%c\n",ans[i]);
	}
    return 0;
}

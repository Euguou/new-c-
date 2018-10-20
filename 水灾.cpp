#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int INF=0x7f7f7f7f;
int n,m,sx,sy,tx,ty;
char map[51][51];
int T[51][51];
int xx[4]={-1,1,0,0};
int yy[4]={0,0,1,-1};
char ch[255];
struct data{
int x,y,t;
};
void bfs1()
{
    queue<data> Q;
    data p;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(map[i][j]=='*')
            {
                p=(data){i,j};
                T[i][j]=0;
                Q.push(p);
            }
		}
           
	}
        
    while(!Q.empty())
    {
        p=Q.front();Q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.x+xx[i],y=p.y+yy[i];
            if(x<1||x>n||y<1||y>m||T[x][y]!=INF) continue;
            T[x][y]=T[p.x][p.y]+1;
            Q.push((data){x,y});
        }
    }
}

void bfs2()
{
    bool vis[51][51],flag=0;
    memset(vis,0,sizeof(vis));
    queue<data> Q;
    data p={sx,sy,0};vis[sx][sy]=1;
    Q.push(p);
    while(!Q.empty())
    {
        p=Q.front();Q.pop();
        if(p.x==tx&&p.y==ty) {flag=1;break;}
        for(int i=0;i<4;i++)
        {
            int x=p.x+xx[i],y=p.y+yy[i];
            if(x<1||x>n||y<1||y>m||T[x][y]<=p.t+1||vis[x][y]) continue;
            vis[x][y]=1;
            Q.push((data){x,y,p.t+1});
        }
    }
    if(flag) printf("%d\n",p.t);
    else printf("ORZ hzwer!!!\n");
}

int main()
{
    scanf("%d %d",&n,&m);
    memset(T,0x7f,sizeof(T));
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch+1);
        for(int j=1;j<=m;j++)
        {
            map[i][j]=ch[j];
            switch(map[i][j])
            {
            case 'S':
                sx=i,sy=j;
                break;
            case 'D':
                tx=i,ty=j;
                T[i][j]=INF-1;
                break;
            case 'X':
                T[i][j]=0;
                break;
            }
        }
    }
    bfs1();
    bfs2();
    return 0;
}

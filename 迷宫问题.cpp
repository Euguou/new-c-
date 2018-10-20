#include <cstring>
#include <Cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream> 
#include <algorithm>
#include <cmath> 
using namespace std;
int N,M;
int map[51][51];
bool f;
int disx,disy,a[51],b[51],soux,souy,totstep;
int dfs(int x,int y,int step)
{
	map[x][y]=step;
	a[step]=x,b[step]=y;
	if(x=disx&&y==disy)
	{
		f=1;
		totstep=step;
	}
	else {
		if(y!=M&&map[x][y+1]==0) dfs(x,y+1,step+1) ;//向右 
		if(!f&&x!=N&&map[x+1][y]==0) dfs(x+1,y,step+1); //向下 
		if(!f&&y!=1&&map[x][y-1]==0) dfs(x,y-1,step+1); //向左 
		if(!f&&x!=1&&map[x-1][y]==0) dfs(x-1,y,step+1); //向上 
	}
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%d",map[i][j]);
		} 
	}
	scanf("%d%d%d%d",&soux,&souy,&disx,&disy);
	dfs(soux,souy,1);
	if(f)
	{
		for(int i=1;i<totstep;i++)
		{
			printf("%d,%d",a[i],b[i]);
		}
	 } 
	else {
		printf("no way");
	}
	return 0;
} 

//https://www.luogu.org/problemnew/show/P1077
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define mod 1000007
using namespace std;
int f[1001][1001];//f[i][j]表示第i盆花后摆j盆的最优解 
int main()
{
	memset(f,0,sizeof(f));
	int n,m,t;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		f[i][0]=1;//初始值全部置为1; 
	}
	for(int i=1;i<=n;i++)//枚举到第i盆花; 
	{
		cin>>t;
		for(int j=0;j<=t;j++)//第i盆花装j盆
		{
			 for(int k=0;k<=m-j;k++)//从已经装k盆转移过来
            {
                if(j==0&&k==0)
                    continue;
                f[i][j+k]+=f[i-1][k];
                f[i][j+k]%=mod;
            }
		}   
	}
	cout<<f[n][m]%mod<<endl;
	return 0; 
}

 

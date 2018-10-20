#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define maxn 11000000
#include <queue>
#include <vector>
#include <map>
using namespace std;
int a[maxn];
int dp[maxn];
int INF=999999999;

int main()
{
	int N,L,R;
	scanf("%d%d%d",&N,&L,&R);
	for(int i=0;i<N;i++)
	{
		scanf("%d" ,&a[i]);
	}
	for(int i=1;i<=110010;i++)
	{
		dp[i]=-1;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=i-R;j<=i-L;j++)
		{
			if(j<0)
			{
				continue;
			}
			dp[i]=max(dp[i],dp[j]+a[i]);
		}
	}
	int ans=*max_element(dp+N-R+1,dp+N); 
	printf("%d",ans);
	return 0;
 } 
/* 
ÊäÈë
5 2 5
0 12 3 11 7 -2
 
Êä³ö
11
*/ 

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#define fo(a,b,c) for(int a=b;a<=c;a++)
#define INF 0x3f3f3f3f
using  namespace  std;
int f[55][55];
char s[55];
int main() 
{
	memset(f, INF, sizeof(f));
	scanf("%s", s + 1);
	int N = strlen(s + 1);
	fo(i,1,N)
	{
		f[i][i] = 1;
	}
	fo(l,1,N)
	{
		fo(i,1,N)
		{
			int j = l + i; 
			if (j > N)
				break;
			if(s[i] == s[j]) 
			{
				if (l == 1)
				{
					f[i][j] = 1;	
				}
				else 
					f[i][j] = min(min(f[i + 1][j], f[i][j - 1]), f[i + 1][j - 1] + 1);
			}
			else 
			{
				for (int k = i; k < j; k++)
				{
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
				}
			}
		}
	}
	printf("%d\n", f[1][N]);
	return 0;
}
/*
输入1： 
AAAAA
输出1：
1

输入2：
RGBBGR
输出2：
3
*/ 



#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int vis[1000001];
int main()
{
	int L,M;
	scanf_s("%d%d", &L, &M);
	for (int i = 0; i < L; i++)
	{
		vis[i] = 0;
	}
	for (int i = 1; i <= M; i++)
	{
		int h, l;
		scanf_s("%d%d", &h, &l);
		for (int j = h; j <= l; j++)
		{
			if (vis[j] == 1)
			{
				continue;
			}
			if(vis[j]==0)
				vis[j] = 1;
		}
	}
	int sum=0;
	for (int i = 0; i <= L; i++)
	{
		if (vis[i] == 0) sum++;
	}
	printf("%d", sum);
	return 0;
}
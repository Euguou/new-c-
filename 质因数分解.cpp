#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int a[1000001],b[10001],c[100001];
int ans=0;
int zs(int x)
{
	int i=2;
	while (i<x){
		if(x%i==0)
		{
			break;
		}
		i++;
	}
	if(i==x)
	{
		return 1;
	}
	else {
		return -1;
	}
}
void ys(int x)
{
    for(int i = 1; i <= x; i ++)
    {
        if(x%i==0) 
        {
         	a[i]=i;
		}
    }
}
int main()
{
	int N;
	cin>>N;
	ys(N);
	for(int i=0;i<N;i++)
	{
		if(zs(a[i])==1)
		{
			b[i]=a[i];
			ans=b[i];
		}
		else continue;
	}
	cout<<ans;
	return 0;
}

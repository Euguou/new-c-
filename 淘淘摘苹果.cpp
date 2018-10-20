#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000001];
int main()
{
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	int hand,ans;
	cin>>hand;
	sort(a,a+10);
	for(int i=0;i<=10;i++)
	{
		if(hand+30>a[i])
		{
			ans++;
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
 } 

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;
int exgcd(long long a, long long b ,long long&x,long long&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int g=exgcd(b,a&b,y,x);
	y-=a/b*x;
	return 0;
}
int main()
{
	long long n,m,x,y,l;
    cin>>x>>y>>m>>n>>l;
    long long b=n-m,a=x-y;
    if(b<0)
    {
        b=-b;
        a=-a;
    }
    int ans;
    exgcd(b,l,x,y);
    if(a%ans!=0)
        cout<<"Impossible";
    else
        cout<<((x*(a/ans))%(l/ans)+(l/ans))%(l/ans);
	cout<<"Impossible"<<endl;
} 

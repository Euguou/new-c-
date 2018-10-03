#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	int find;
	cin>>find;
	int b=lower_bound(a,a+N,find)-a;
	cout<<b+1<<endl;
	return 0;
 } 

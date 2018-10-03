#include <iostream>
#include <algorithm> 
using namespace std;
int a[10001];
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
	int b=binary_search(a,a+N,find);
	b?cout<<"yes":cout<<"no";
	return 0;
 } 

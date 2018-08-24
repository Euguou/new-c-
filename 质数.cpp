#include <iostream>
using namespace std;
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
int main()
{
	int N;
	cin>>N;
	cout<<zs(N);
 } 

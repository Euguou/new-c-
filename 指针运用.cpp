#include <iostream>
#define f(a,b) if(a==b)
using namespace std;
int *p;
int a,b;
int main()
{
	cin>>a>>b;
	if(a>b)  *p=a;
	if(a<b)  *p=b;
	*p+=10;
	cout<<*p<<endl;
	return 0; 
 } 

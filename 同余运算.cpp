#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double a,b;
	cin>>a>>b;
	int a1,b1;
	a1=a*100;
	b1=b*100;
	double c;
	c=a1%b1;
	double c1=c/100;
	printf("%.2f",c1);
	return 0;
 } 

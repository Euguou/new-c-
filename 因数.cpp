#include<stdio.h>
#include <iostream>
using namespace std;
void ys(int n)
{
    for(int i = 1; i <= n; i ++)
    {
        if(n%i==0) 
        {
        	cout<<i<<" ";
		}
    }
}
int main()
{
 int i,j,n;
 cin>>n;
 ys(n);
 return 0;
} 

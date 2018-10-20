#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define N 1001
using namespace std;
int n;
char m[N];
int ans;
int main()
{
	scanf("%d%s",&n,&m);
    for(int i=0;m[i];i++)
    {
    	ans=(ans*10+m[i]-'0')%n;
	}
	printf("%d",ans?ans:n);
	return 0; 
} 

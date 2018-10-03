#include <bits/stdc++.h>
#include <algorithm>
#include <map>
using namespace std;
int N,M;
int cnt;
int telephone[1000001];
string s[100001];
int f;
map <int,string> P;
p enumMap;
struct Node{
	int son[11],name[20];
};
int fin(int a)
{
	int b;
	return b=binary_search(telephone , telephone+N , a);
}
int main()                                         
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>telephone[i]>>s[i];
	}
	int M;
	for(int i=0;i<M;i++)
	{
		cin>>f;
		fin(f);
	}
	for(int i=0;i<N;i++)
	{
		
	}
	return 0;
} 

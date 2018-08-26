//https://www.luogu.org/problemnew/show/P1077
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define mod 1000007
using namespace std;
int f[1001][1001];//f[i][j]��ʾ��i�軨���j������Ž� 
int main()
{
	memset(f,0,sizeof(f));
	int n,m,t;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		f[i][0]=1;//��ʼֵȫ����Ϊ1; 
	}
	for(int i=1;i<=n;i++)//ö�ٵ���i�軨; 
	{
		cin>>t;
		for(int j=0;j<=t;j++)//��i�軨װj��
		{
			 for(int k=0;k<=m-j;k++)//���Ѿ�װk��ת�ƹ���
            {
                if(j==0&&k==0)
                    continue;
                f[i][j+k]+=f[i-1][k];
                f[i][j+k]%=mod;
            }
		}   
	}
	cout<<f[n][m]%mod<<endl;
	return 0; 
}

 

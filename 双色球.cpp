#include<iostream>
#include<cmath>

using namespace std;

int n,cnt=0;
int s[51];
long long ans;

int main()
{
    cin>>n;getchar();
    for(int i=1;i<=n;i++)
    {
        char ch=getchar();
        if(ch=='B') s[++cnt]=i;
    }
    for(int i=1;i<=cnt;i++)
    {
        ans=+(long long)pow((double)2,s[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}

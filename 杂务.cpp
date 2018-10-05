#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using std::max;

const int N=10000+50;
int f[N];
int main(){
    int n;
    scanf("%d",&n);
    int maxn=0;
    for(int i=1,t,len,u;i<=n;i++){
        scanf("%d%d",&t,&len);
        f[i]=len;
        while(scanf("%d",&u)==1 && u)f[i]=max(f[i],f[u]+len);
        maxn=max(maxn,f[i]);
    }
    printf("%d\n",maxn);
    return 0;
}

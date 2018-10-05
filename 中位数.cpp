#include<cstdio>
#include<map>
using std::map;

typedef long long LL;
const int N = 100000+100;
int n,b;
int a[N];
map<int,int>mpx,mpy;
int x[N],tx,y[N],ty;
int main(){
	scanf("%d%d",&n,&b);
	int pos;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==b)pos=i;
	}
	
	int now=0;
	++mpx[0];
	for(int i=pos-1;i>=1;i--){
		now+=a[i]>b?1:-1;
		++mpx[now];
	}
	
	now=0;
	++mpy[0];
	for(int i=pos+1;i<=n;i++){
		now+=a[i]>b?1:-1;
		++mpy[now];
	}
	LL ans=0;
	for(map<int,int>::iterator it=mpx.begin();it!=mpx.end();++it){
		ans+=(LL)mpy[-it->first]*it->second;
	}
	printf("%lld\n",ans);
	return 0;
}

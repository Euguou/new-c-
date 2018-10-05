#include<cstdio>
const int N = 50000+10;
int l,n,m;
int d[N];
inline bool check(int len){
	int now=0;
	int num=0;
	for(int i=1;i<=n&&num<=m;i++){
		if(d[i]-now >= len) now=d[i];
		else ++num;
	}
	if(l-now<len) ++num;
	//printf("len %d num %d\n",len,num);
	return num<=m;
}
int main(){
	scanf("%d%d%d",&l,&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	int L=1,R=l;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(check(mid))L=mid;
		else R=mid-1;
	}
	printf("%d\n",L);
	return 0;
}

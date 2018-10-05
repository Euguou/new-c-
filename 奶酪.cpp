#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
typedef long long LL;
typedef unsigned long long ULL;
using std::cin;
using std::cout;
using std::endl;
const int N = 1000+10;
int n,h,r;
int fa[N];
int p[N][3];
#define DING (n+1)
#define DI (n+2)
int find(int x){
	return fa[x] = (fa[x]==x ? x : find(fa[x]));
}
inline void link(int x,int y){
	fa[find(x)]=find(y);
}
inline ULL pw2(int x){
	return x>=0 ? (ULL)x*x : (ULL)(-x)*(-x);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>h>>r;
		for(int i=1;i<=n+2;i++)fa[i]=i;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&p[i][0],&p[i][1],&p[i][2]);
			if(p[i][2]+r>=h)link(i,DING);
			if(p[i][2]-r<=0)link(i,DI);
			for(int j=1;j<i;j++){
				//sqrt[(p[i][0]-p[j][0])^2+(p[i][1]-p[j][1])^2+(p[i][2]-p[j][2])^2] <= 2*r
				//(p[i][0]-p[j][0])^2+(p[i][1]-p[j][1])^2+(p[i][2]-p[j][2])^2 <= 4*r*r
				if( pw2(p[i][0]-p[j][0])+pw2(p[i][1]-p[j][1])+pw2(p[i][2]-p[j][2])<=4*pw2(r)) {
					link(i,j);
				}
			}
		}
		puts(find(DING)==find(DI)?"Yes":"No");
	}
	return 0;
} 

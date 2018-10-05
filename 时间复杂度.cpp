#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>

using std::max;

typedef long long LL;
const int LEN = 110;

int T;
int L,n;
char str[100];
struct Node{
	int opt;
	int id,l,r;
}t[LEN];
int sta[LEN][2],top;
bool vis[LEN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&L,str);//O(1)表示常数复杂度，O(n^w)表示复杂度
		if(str[2]=='1')n=0;
		else{
			n=str[4]-'0';
			if(str[5]!=')'){
				n=n*10+str[5]-'0';
			}
		}
		for(int i=1;i<=L;i++){
			scanf("%s",str);
			if(str[0]=='F'){// F i x y
				t[i].opt = 1;
				scanf("%s",str);
				t[i].id = str[0]-'a';
				
				scanf("%s",str);
				if(str[0]=='n')t[i].l=-1;
				else{
					t[i].l=str[0]-'0';
					if(str[1])t[i].l=t[i].l*10+str[1]-'0';
				}
				
				scanf("%s",str);
				if(str[0]=='n')t[i].r=-1;
				else{
					t[i].r=str[0]-'0';
					if(str[1])t[i].r=t[i].r*10+str[1]-'0';
				}
			}else{
				t[i].opt = 2;
			}
		}
		
		top=0;
		memset(vis,0,sizeof(vis));
		sta[0][0]=0;
		sta[0][1]=1;
		int now=0;
		int ans=1;
		for(int i=1;i<=L;i++){
			if(t[i].opt==1){
				++now;
				++top;
				if(vis[t[i].id]){
					ans=0;
					break;
				}
				vis[t[i].id]=true;
				sta[top][0]=t[i].id;
				if(t[i].l==-1 && t[i].r==-1){// n n
					sta[top][1]=sta[top-1][1];
				}else if(t[i].l==-1){// n x
					sta[top][1]=0;
				}else if(t[i].r==-1){// x n
					sta[top][1]=sta[top-1][1]?sta[top-1][1]+1:0;
				}else{
					if(t[i].l<=t[i].r){// s l
						sta[top][1]=sta[top-1][1]?sta[top-1][1]:0;
					}else{//l s
						sta[top][1]=0;
					}
				}
				ans=max(ans,sta[top][1]);
			}else{
				--now;
				if(now<0){
					ans=0;
					break;
				}
				vis[sta[top][0]]=false;
				top--;
			}
		}
		ans--;
		if(now!=0)ans=-1;
		if(ans==-1)puts("ERR");
		else if(ans==n)puts("Yes");
		else puts("No");
	}
	return 0;
}

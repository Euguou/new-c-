#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
typedef long long LL;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void work(){
	int n=10;
	for(int a=2;a<=n;a++){
		for(int b=2;b<a;b++){
			if(gcd(a,b)!=1)printf("(%d,%d)%3d\t",a,b,0);
			else{
				int ans=0;
				for(int x=1;x<=100000;x++){
					bool ok=true;
					for(int i=0;i*a<=x;i++){
						if((x-i*a)%b==0){
							ok=false;
							break;
						}
					}
					if(ok)ans=x;
				}
				printf("(%d,%d)%3d\t",a,b,ans);
			}
		}
		puts("");
	}
}
int main(){
	work();
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%lld\n",(LL)(a-1)*(b-1)-1);// (LL)a*b -a-b
	return 0;
} 

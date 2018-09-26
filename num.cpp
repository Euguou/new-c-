#include <iostream>
#define fo(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
void write(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main()
{
	int num;
	int N;
	read(N);
	int K;
	read(K);
	fo(i,0,N)
	{
		
	}
	return 0;
}

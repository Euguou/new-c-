//https://www.luogu.org/problemnew/show/P1731
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[21],b[21],m,n,ans;//a存储表面积,b存储体积 
void search(int v,int s,int p,int r,int h)//v为已用体积，s为已有表面积，p为剩余层数，r为半径，h为高 
{
    int i,j,hh;
    if (p==0)//蛋糕已完成
        {
        if (v==n&&s<ans)//判断是否符合要求并得到更优解
                ans=s;//更新最优解
        return ;
        }
        if(v+b[p-1]>n) return ;//体积超出 
        //if(s+a[p-1]>ans) return ;//表面积超出 
        if(2*(n-v)/r+s>=ans)  return; //重点：当前的表面积+余下的侧面积>当前最优值
        //剩余表面积FS>=2*V剩/r   
        //若FS+s>=ans 则不符合 
         for(i=r-1;i>=p;i--)//枚举上一层的半径
         {
            if(p==m) s=i*i;
            hh=min((n-v-b[p-1])/(i*i),h-1);
            for(j=hh;j>=p;j--)//枚举上一层的高
            search(v+i*i*j,s+2*i*j,p-1,i,j);
         }
}
int main()
{
      cin>>n>>m;
      ans=214748364;
      a[0]=b[0]=0;
      for(int i=1;i<21;i++)
      {
        b[i]=b[i-1]+i*i*i;
      }
      search(0,0,m,n+1,n+1);
      if(ans==2147483647) cout<<'0';
      else cout<<ans;
      return 0;
}

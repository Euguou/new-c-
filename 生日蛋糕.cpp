//https://www.luogu.org/problemnew/show/P1731
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[21],b[21],m,n,ans;//a�洢�����,b�洢��� 
void search(int v,int s,int p,int r,int h)//vΪ���������sΪ���б������pΪʣ�������rΪ�뾶��hΪ�� 
{
    int i,j,hh;
    if (p==0)//���������
        {
        if (v==n&&s<ans)//�ж��Ƿ����Ҫ�󲢵õ����Ž�
                ans=s;//�������Ž�
        return ;
        }
        if(v+b[p-1]>n) return ;//������� 
        //if(s+a[p-1]>ans) return ;//��������� 
        if(2*(n-v)/r+s>=ans)  return; //�ص㣺��ǰ�ı����+���µĲ����>��ǰ����ֵ
        //ʣ������FS>=2*Vʣ/r   
        //��FS+s>=ans �򲻷��� 
         for(i=r-1;i>=p;i--)//ö����һ��İ뾶
         {
            if(p==m) s=i*i;
            hh=min((n-v-b[p-1])/(i*i),h-1);
            for(j=hh;j>=p;j--)//ö����һ��ĸ�
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

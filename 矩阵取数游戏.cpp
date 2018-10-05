#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[100][100][500];
int n,m;
char str[50];
int t[500],t2[500],t3[500],ans[500];
void read(int *a){
    scanf("%s",str+1);
    int len=strlen(str+1);
    for(int i=1;i<=len;i++){
        a[i]=str[len-i+1]-'0';
    }
    a[0]=len;
}
void out(int*a){
    printf("\n******len   %d   ",a[0]);
    for(int i=a[0];i>=1;i--){
        printf("%d",a[i]);
    }
    printf("\n");
}
void add(int *a,int *b,int *c){
    memset(c,0,sizeof(int)*500);
    if(a[0]<b[0])swap(a,b);
    memcpy(c,a,sizeof(int)*500);
    for(int i=1;i<=b[0];i++){
        c[i]+=b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    for(int i=b[0]+1;i<=c[0];i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[c[0]+1])c[0]++;
}
void max(int *a,int *b,int *c){
    memset(c,0,sizeof(c));
    if(a[0]!=b[0]){
        if(a[0]>b[0])memcpy(c,a,sizeof(int)*500);
        else memcpy(c,b,sizeof(int)*500);
        return;
    }
    for(int i=a[0];i>=1;i--){
        if(a[i]!=b[i]){
            if(a[i]>b[i])memcpy(c,a,sizeof(int)*500);
            else memcpy(c,b,sizeof(int)*500);
            return;
        }
    }
    memcpy(c,b,sizeof(int)*500);
}
void work() {
    for(int len=2;len<=m;len++){
        for(int beg=1;beg+len-1<=m;beg++){
            int end=beg+len-1;
            add(dp[beg][end-1],dp[beg][end-1],t3);
            add(t3,dp[end][end],t);
            add(dp[beg+1][end],dp[beg+1][end],t3);
            add(t3,dp[beg][beg],t2);
            max(t,t2,dp[beg][end]);
            //dp[beg][end]=max(dp[beg][end-1]*2+dp[end][end]\
            //,dp[beg][beg]+dp[beg+1][end]*2);
        }
    }
}
void output(int *a){
    for(int i=a[0];i;i--)printf("%d",a[i]);
}
int main() {
    scanf("%d%d",&n,&m);
    memset(ans,0,sizeof(ans));
    ans[0]=1;
    while(n--){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            read(dp[i][i]);
        }
        work();
        add(dp[1][m],dp[1][m],t);
        add(t,ans,t2);
        memcpy(ans,t2,sizeof(t2));
        //out(ans);
    }
    output(ans);
    return 0;
}
